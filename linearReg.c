#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SETSIZE 958
#define TRAINSIZE 766   // 80% of Set
#define TESTSIZE 192    // 20% of Set

void scan_datafileint(int data[][10], int filesize);
void shuffle_data(int data[][10], int rows);
void ml_learn(int data[][10], int setsize, float weights[9]);
void ml_test(int data[][10], int start_pos, int end_pos, float weights[9]);

int main (){
    float weight[9]= {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
    int set[958][10], file = 958;
    scan_datafileint(set, file);
    shuffle_data(set, file);
    ml_learn(set, TRAINSIZE, weight);
    ml_test(set, 0, 766, weight);
    ml_test(set, 766, SETSIZE, weight);    // Test Algo against Rows 766~958 of the Set
    //print_set(set, file);
    return 0;
}

void scan_datafileint(int data[][10], int filesize)
{
    FILE* dataset;
    dataset = fopen("C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt", "r");
    char data_line[27], value; // holds the current data line string from dataset
    int iter = 0, pos_iter;
    
    while(fgets(data_line, 28, dataset) != NULL && iter < filesize){    // Convert character values from data file to integer values in 2d array of 958 rows and 10 columns
        //printf("Fetched %s\nRow %d:", data_line,iter+1);
        for(pos_iter=0;pos_iter<9;pos_iter++){ // Set Element 1-9 o,x,b =  -1, 1, 0
            value = data_line[pos_iter*2];  // value <- Board character value and skips commas
            if(value == 'o'){
                data[iter][pos_iter] = -1;
            }else if(value == 'x'){
                data[iter][pos_iter] = 1;
            }
            else{   // blank board value 'b' = 0
                data[iter][pos_iter] = 0;
            }
            //printf("%d", data[iter][pos_iter]);
        }
        if(data_line[18] == 'p'){   // set Element 10 as -1 or 1 =  Lose/Win
            data[iter][9] = 1;
        }
        else{
            data[iter][9] = -1;
        }
        //printf(" Result: %d\n", data[iter][9]);
        iter++;
    }

    fclose(dataset);
}

void shuffle_data(int data[][10], int rows){
    srand(time(NULL));
    int j=0, temp, k;
    for (int i= rows-1; i>0; i--){
        //printf("Swapping Row %d & %d\n", i+1, j+1);
        j = rand() % (i + 1);
        //swap_addr(data[i], data[j]);
        for(k=0; k<10; k++){
            temp = data[i][k];
            data[i][k] = data[j][k];
            data[j][k] = temp;
        }
    }
}

void print_set(int data[][10], int rows){
    int i,j;
    for(i=0; i<958; i++){
        printf("\nRow %d: ", i+1);
        for(j=0; j<10; j++){
            printf("%d,", data[i][j]);
        }
    }
}

void ml_learn(int data[][10], int setsize, float weights[9]){
    int row, iter;
    float predict_y=0.0, error=0.0, errSum=0.0;
    float swe[9] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};  //sum of weightage errors[9]

    for (row=0; row<setsize; row++){
        predict_y = 0;
        for(iter=0; iter<9; iter++){
            predict_y += weights[iter] * data[row][iter];   // predict_y = sum(x[iter]*weight[iter]);
        }
        
        error = predict_y - (1.0 * data[row][9]);   // Compare predicted vs actual result
        errSum += error;
        printf("\nRow %d: Err. %.2f", row+1, error);

        //weightage change
        for(iter=0; iter<9; iter++){
            swe[iter] += (errSum/(row+1)) * data[row][iter];
            //swe[iter] += errSum * data[row][iter];
            weights[iter] -= 0.01/setsize * swe[iter];
            //printf(" %.2e,", weights[iter]);
        }
    }
    printf("\nLearning Done, Final Weights are:\n");
    for(row=0;row<9;row++){
        printf("W%d: %f\n", row+1, weights[row]);
    }
}

void ml_test(int data[][10], int start_pos, int end_pos, float weights[9]){
    int row, iter, errCount=0;
    //int start_pos = setsize - testsize;         //start row will be where testing set is located,
    float predict_y, error; 

    for(row=start_pos; row<end_pos; row++){    //iterate to end of set, total 20% of whole set
        predict_y = 0;
        for(iter=0; iter<9; iter++){    // predict y value 
            predict_y += weights[iter] * data[row][iter];   
        }

        error = predict_y - (1.0 * data[row][9]);   // Compare predicted vs actual result
        if ((predict_y < 0 && data[row][9] > 0) || (predict_y > 0 && data[row][9] < 0)){  // check if algo predicted a correct win or loss
            errCount++;
        }
        printf("\nRow %d Predicted: %f, Actual: %d\n", row+1, predict_y, data[row][9]);
    }
    printf("Test Completed, Total Errors: %d", errCount);
}