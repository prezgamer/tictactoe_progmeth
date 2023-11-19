#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

#define totalDataSize 958
#define trainingDataSize 766 //80%
#define testingDataSize 192 //20%

int main() {

    // Open the data file for reading
    FILE *txtFile;
    txtFile = fopen("C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt", "r");

    if (txtFile==NULL) {
        printf("\n file cannot be opened");
        return 1;
    } else //read the file
    {
        printf("File can be read");
        // fprintf("\n %s", txtFile);
        // char line[6];
        // //char text[24906];  // Adjust the buffer size based on your needs
        // while (fgets(line, 6, txtFile) != NULL) 
        // {
        //     // text[24906] = line[6];
        //     // printf("%s",text);
        //     printf("%s", line);
        // }
    }



    //  char totalData1[] = 
    //  {
    //      "o,b,o,x,x,x,x,b,o,positive"
    //  };
    //  char totalData2[] = 
    //  {
    //      "o,b,o,x,x,x,x,b,o,negative"
    //  };
    // printf("Char: %s",totalData1);
    // printf("Char: %s",totalData2);
    // char trainingData[766];
    // char testingData[192];

    // for (int n = 0; n < totalDataSize; n++)
    // {
    //     fscanf(txtFile, totalData[n]);
    //     printf("%s", totalData[n]);
    // }
    
        
    // Close the file
    fclose(txtFile);

    return 0;
}
