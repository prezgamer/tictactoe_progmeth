#include <stdio.h>

// Function to split data into training and testing sets
void splitData(float data[], int size, float trainingData[], float testingData[], float splitRatio) {
    int trainingSize = size * splitRatio;
    int testingSize = size - trainingSize;

    // Copy the first 'trainingSize' elements to trainingData
    for (int i = 0; i < trainingSize; ++i) {
        trainingData[i] = data[i];
    }

    // Copy the remaining elements to testingData
    for (int i = 0; i < testingSize; ++i) {
        testingData[i] = data[trainingSize + i];
    }
}

// Function to perform linear regression
void linearRegression(float x[], float y[], int size) {
    // Implement your linear regression logic here
    // For simplicity, let's assume a simple linear regression: y = mx + b

    // Calculate mean of x and y
    float meanX = 0, meanY = 0;
    for (int i = 0; i < size; ++i) {
        meanX += x[i];
        meanY += y[i];
    }
    meanX /= size;
    meanY /= size;

    // Calculate the coefficients
    float numerator = 0, denominator = 0;
    for (int i = 0; i < size; ++i) {
        numerator += (x[i] - meanX) * (y[i] - meanY);
        denominator += (x[i] - meanX) * (x[i] - meanX);
    }

    // Calculate the slope (m) and intercept (b)
    float slope = numerator / denominator;
    float intercept = meanY - slope * meanX;

    // Display the linear regression equation
    printf("\nLinear Regression Equation: y = %.2fx + %.2f\n", slope, intercept);
}

int main() {
    // Example data
    float allData[] = {1, 2, 3, 4, 5,6,8,9,22,13,56};

    // Specify the split ratio (80:20)
    float splitRatio = 0.80;

    // Calculate the sizes of training and testing sets
    int dataSize = sizeof(allData) / sizeof(allData[0]);
    int trainingSize = dataSize * splitRatio;
    int testingSize = dataSize - trainingSize;

    // Create arrays to store training and testing data
    float trainingData[trainingSize];
    float testingData[testingSize];

    // Split the data
    splitData(allData, dataSize, trainingData, testingData, splitRatio);

    // Display training data
    printf("Training Data: ");
    for (int i = 0; i < trainingSize; ++i) {
        printf("%.2f ", trainingData[i]);
    }

    // Perform linear regression on the training data
    linearRegression(trainingData, trainingData, trainingSize);

    return 0;
}
