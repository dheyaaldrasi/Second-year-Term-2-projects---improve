import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression


data = pd.read_csv('Salary_Data.csv')
print(data)

plt.scatter(data['YearsExperience'], data['Salary'])
x=data['YearsExperience']
y=data['Salary']




