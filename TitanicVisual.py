import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

titanic_data = pd.read_csv('titanic.csv')

plt.figure(figsize=(8, 6))
sns.countplot(data = titanic_data, x = 'Pclass')
plt.title("hello world")
plt.xlabel("pclass")
plt.ylabel('count')
plt.show()

plt.figure(figsize=(8, 6))
sns.histplot(titanic_data['Age'], bins=20, kde=True)
plt.title("hello world")
plt.xlabel("Age")
plt.ylabel("Frequency")
plt.show()

numeric_columns = titanic_data.select_dtypes(include=['float64', 'int64'])

# Plotting the correlation heatmap
plt.figure(figsize=(8, 6))
sns.heatmap(numeric_columns.corr(), annot=True, cmap='coolwarm')
plt.title("Correlation Heatmap")
plt.show()
