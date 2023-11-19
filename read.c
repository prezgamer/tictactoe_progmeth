#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

int main() {
    // Open the data file for reading
    FILE *file = fopen("tic-tac-toe.csv", "r");
    if (!file) {
        fprintf(stderr, "Error opening the file.\n");
        return 1;
    }

    // Declare variables to store data
    float data[MAX_ROWS][MAX_COLS];
    int numRows = 0, numCols = 0;

    // Read data from the file
    while (fscanf(file, "%f", &data[numRows][numCols]) == 1) {
        numCols++;
        if (numCols >= MAX_COLS) {
            // Increase MAX_COLS if your data has more columns than expected
            fprintf(stderr, "Too many columns in the data file.\n");
            return 1;
        }

        // Check for newline to move to the next row
        char ch = fgetc(file);
        if (ch == '\n' || ch == EOF) {
            numRows++;
            numCols = 0;

            if (numRows >= MAX_ROWS) {
                // Increase MAX_ROWS if your data has more rows than expected
                fprintf(stderr, "Too many rows in the data file.\n");
                return 1;
            }
        }
    }

    // Close the file
    fclose(file);

    // Now you can use the 'data' array in your program

    // Example: Print the data
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
