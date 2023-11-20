#include <stdio.h>
#include <string.h>

int main() 
{
    FILE *txtFile;
    txtFile = fopen("C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt", "r");
    
    // = txtFile;//"x,x,x,x,o,o,x,o,o,positive";
    char *token;
    char *x_elements[10]; // Assuming a maximum of 10 elements for 'x'
    char *y; // For 'positive'
    const char *separator = ",";

    char text[3000];
    
    char input[24];
    while (fgets(input, 30, txtFile) != NULL) 
    {
        printf("\n %s", input);

    }

    printf("\n %s",text);

    // // Tokenize the input string based on ","
    // token = strtok(input, separator);

    // // Loop through the tokens and store them in x_elements and y
    // int i = 0;
    // while (token != NULL) {
    //     if (strcmp(token, "positive") == 0) {
    //         y = token;
    //     } else {
    //         x_elements[i++] = token;
    //     }
    //     token = strtok(NULL, separator);
    // }

    // // Print 'x' elements
    // printf("x: ");
    // for (int j = 0; j < i; ++j) {
    //     printf("%s, ", x_elements[j]);
    // }
    
    // // Print 'y' element
    // printf("\n y: %s\n", y);

    // return 0;
} 
//     struct myStructure s1[956];

//   //Assign a value to the string using the strcpy function
//     strcpy(s1[0].xob, "x,x,x,x,o,o,x,o,o");
//     strcpy(s1[0].posNeg, "positive");

//     strcpy(s1[0].xob, "x,x,x,x,o,o,o,x,o");
//     strcpy(s1[0].posNeg, "positive");

//     strcpy(s1[0].xob, "x,x,x,x,o,o,o,o,x");
//     strcpy(s1[0].posNeg, "positive");

//     strcpy(s1[0].xob, "x,x,x,x,o,o,o,b,b");
//     strcpy(s1[0].posNeg, "positive");

//     strcpy(s1[0].xob, "x,x,x,x,o,o,x,o,o");
//     strcpy(s1[0].posNeg, "positive");

//     strcpy(s1[0].xob, "x,x,x,x,o,o,x,o,o");
//     strcpy(s1[0].posNeg, "positive");

    // strcpy(s1[0].xob, "x,x,x,x,o,o,x,o,o");
    // strcpy(s1[0].posNeg, "positive");



//   // Print the value
//     for (int i = 0; i < 2; i++)
//     {   
//         printf("\n Pattern: %s", s1[i].xob);
//         printf("\n Pattern: %s", s1[i].posNeg);
//     }
    

    // // Open the data file for reading
    // FILE *txtFile;
    // txtFile = fopen("C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt", "r");

    // if (txtFile==NULL) {
    //     printf("\n file cannot be opened");
    //     return 1;
    // } else //read the file
    // {
    //     char line[20];
    //     char test[5] = "hello";
        
    //     while (fgets(line, 19, txtFile) != NULL) 
    //     {
        
    //         printf("\n %s", line);


    //         // if (line[18] == 'p')
    //         // {
    //         //     printf("\n it is positive" );
    //         // } else {
    //         //     printf("\n it is negative" );
    //         // }
    //     }
    // }

    // printf("\n\n xob of a: %s, posNeg of a: %s", a.xob, a.posNeg);

    // fclose(txtFile);

    // return 0;

