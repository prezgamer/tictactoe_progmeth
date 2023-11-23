//C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt
#include <stdio.h>
#include <string.h>

int main() 
{
    // // Declare an array of pointers to strings
    // char *strings[] = {"Hello", "World", "C", "Programming"};

    // // Access and print each string
    // for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i) {
    //     printf("String %d: %s\n", i + 1, strings[i]);
    // }

    // return 0;

    // Open the file in read mode
    FILE *file = fopen("C:/Users/Andrew Foo/Desktop/CSC1003 Programming Methology/tictactoe_progmeth/tictactoe.txt", "r");

    // Check if the file is opened successfully
    if (file == NULL) {
        perror("Error opening file");
        return 1; // Return an error code
    }
    
    int xValue[950];
    int yValue[950];

    char line[100]; // Assuming a maximum line length of 100 characters
    char *token;
    char *x_elements[10]; // Assuming a maximum of 10 elements for 'x'
    char *result; // For 'positive' or 'negative'
    const char *separator = ",";

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line based on ","
        token = strtok(line, separator);

        // Loop through the tokens and store them in x_elements and result
        int i = 0;
        while (token != NULL) {
            if (strcmp(token, "positive\n") == 0 || strcmp(token, "negative\n") == 0) {
                result = token;
            } else {
                x_elements[i++] = token;
            }
            token = strtok(NULL, separator);
        }

        //check for the x elements
        // Print 'x' elements
        printf("\n x: ");
        for (int j = 0; j < i; ++j) {

            if (strcmp(x_elements[j],"x") == 0)
            {
                xValue[0] = 1;
                printf("\n xValue: %d",xValue[0]);
            } 
            else if (strcmp(x_elements[j],"o") == 0)
            {
                xValue[0] = -1;
                printf("\n xValue: %d",xValue[0]);
            } else if (strcmp(x_elements[j],"b") == 0)
            {
                xValue[0] = 0;
                printf("\n xValue: %d",xValue[0]);
            }
        }

        //printf("\n y: %s", result);

        // Print result
        if (strcmp(result,"positive") == 0)
        {
            yValue[0] = 1;
            printf("\n y: %d", yValue[0]);
        } 
        else if (strcmp(result,"negative") == 0) 
        {
            yValue[0] = -1;
            printf("\n y: %d", yValue[0]);
        } else {
            printf("\n y: Unable to print");
        }
    }

    // Close the file
    fclose(file);

    return 0;
}
