%matplotlib inline
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from sklearn.metrics import mean_squared_error, r2_score
from sklearn import datasets, linear_model 
from sklearn.model_selection import train_test_split

from sklearn.linear_model import LinearRegression
from sklearn.linear_model import Ridge
from sklearn.preprocessing import MinMaxScaler

data_diabetes = datasets.load_diabetes()
X_diabetes, y_diabetes = data_diabetes.data, data_diabetes.target

X_data = data_diabetes.data
Y_data = data_diabetes.target

X_train, X_test, y_train, y_test = train_test_split(X_data, Y_data, test_size = 0.3, random_state = 0)

my_LR = LinearRegression()
my_LR.fit(X_train, y_train)

print("Result of Linear Regression:\n")
print("Intercept = {}\n".format(my_LR.intercept_))
print("Coefficients = {}\n".format(my_LR.coef_))

y_predict_test = my_LR.predict(X_test)

MSE_test = mean_squared_error(y_test, y_predict_test)
RMSE_test = np.sqrt(MSE_test)

R2_score_test = my_LR.score(X_test, y_test)


print("MSE on the test set: {:.3f}".format(MSE_test))
print("RMSE on the test set: {:.3f}".format(RMSE_test))
print("R2 score on the test set: {:.3f}".format(R2_score_test))