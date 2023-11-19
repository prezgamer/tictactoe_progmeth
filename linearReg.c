#include<math.h>
#include<stdio.h>

//y is training data
//x is testing data

//both training data and testing data have x and y
//according to a certain gradient (m), it looks at the gradient
//and it checks how good it is at a progression, both training and testing data will have x and y
//look at the data, 

void calculatemc(float )
{

}

void linearRegression(float X[], float y[], int n, float *slope, float *intercept) {
    // Placeholder implementation of linear regression
    // You would replace this with your actual linear regression algorithm
    // ...

    // For simplicity, let's assume a simple linear regression model:
    // y = mx + b
    // where m is the slope, b is the intercept

    // Calculate mean of X and y
    float mean_X = 0.0, mean_y = 0.0;
    for (int i = 0; i < n; ++i) {
        mean_X += X[i];
        mean_y += y[i];
    }
    mean_X /= n;
    mean_y /= n;

    // Calculate slope (m) and intercept (b)
    float numerator = 0.0, denominator = 0.0;
    for (int i = 0; i < n; ++i) {
        numerator += (X[i] - mean_X) * (y[i] - mean_y);
        denominator += pow(X[i] - mean_X, 2);
    }

    *slope = numerator / denominator;
    *intercept = mean_y - (*slope * mean_X);
}

int main(){
    int n,i;
    float x,y,m,c,d;
    float sumx=0,sumxsq=0,sumy=0,sumxy=0;


    //number of items in the table
    printf("enter the number of values for n: \n");
    scanf("%d",&n);

    //calcuate for all values of x and y
    for(i=0;i<n;i++)
    {
        printf("\n enter values of x[%d]: ", i+1);
        scanf("%f",&x);
        printf("\n enter values of y[%d]: ", i+1);
        scanf("%f",&y);

        sumx=sumx+x;
        sumxsq=sumxsq+(x*x);
        sumy=sumy+y;
        sumxy=sumxy+(x*y);
    }
    d=n*sumxsq-sumx*sumx;
    m=(n*sumxy-sumx*sumy)/d; //calculate for m
    c=(sumy*sumxsq-sumx*sumxy)/d; //calculate for c

    printf("M=%f\tC=%f\n",m,c);
}