import pandas as pd
import numpy as np

# Program 1
data = {'A': 10, 'B': 20, 'C': 30, 'D': 40}
my_series = pd.Series(data)
print("Pandas Series:")
print(my_series)
print("\nAccessing elements by label:")
print("Value at label 'A':", my_series['A'])
print("Value at label 'C':", my_series['C'])
print("\nAccessing elements by position:")
print("The first element:", my_series[0])
print("The second element:", my_series[1])
print("\nArithmetic operations on the Series:")
result = my_series * 2
print("Series multiplied by 2:")
print(result)
print("\nFiltering elements:")
filtered_series = my_series[my_series > 20]
print("Elements greater than 20:")
print(filtered_series)

# Program 2
data_dict = {'apple': 3, 'banana': 2, 'cherry': 5, 'date': 1}
fruits_series = pd.Series(data_dict)
print(fruits_series)

# Program 3
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 35, 40],
    'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago']
}
df = pd.DataFrame(data)
print(df)

# Program 4
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, 22],
    'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago', 'Miami']
}
df = pd.DataFrame(data)
print("DataFrame Statistics (describe()):")
print(df.describe())
print("\nFirst 3 rows (head()):")
print(df.head(3))
print("\nLast 2 rows (tail()):")
print(df.tail(2))

# Program 5
data = {'A': [1, 2, 3, 4], 'B': [5, 6, 7, 8]}
df = pd.DataFrame(data)
numpy_array_df = df.values
series = pd.Series([10, 20, 30, 40])
numpy_array_series = series.values
numpy_array_df_alt = df.to_numpy()
numpy_array_series_alt = series.to_numpy()
print("DataFrame to NumPy Array (Using .values attribute):")
print(numpy_array_df)
print("\nSeries to NumPy Array (Using values attribute):")
print(numpy_array_series)
print("\nDataFrame to NumPy Array (Using to_numpy() method):")
print(numpy_array_df_alt)
print("\nSeries to NumPy Array (Using to_numpy() method):")
print(numpy_array_series_alt)

# Program 6
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 22, 35],
    'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago']
}
df = pd.DataFrame(data)
selected_columns = df[['Name', 'Age']]
print("Selected Columns:")
print(selected_columns)
df['Salary'] = [50000, 60000, 45000, 70000]
print("\nDataFrame After Adding 'Salary' Column:")
print(df)
df.drop('City', axis=1, inplace=True)
print("\nDataFrame After Deleting 'City' Column:")
print(df)

# Program 7
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 22, 35],
    'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago']
}
df = pd.DataFrame(data)
selected_row = df.loc[1]
print("Selected Row:")
print(selected_row)

new_row = pd.Series(['Eva', 28, 'Miami'], index=['Name', 'Age', 'City'])
df = pd.concat([df, pd.DataFrame([new_row], columns=df.columns)], ignore_index=True)
print("\nDataFrame After Adding New Row:")
print(df)

df.drop(2, inplace=True)
print("\nDataFrame After Deleting Third Row:")
print(df)

# Program 8
data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David'],
    'Age': [25, 30, 22, 35],
    'Salary': [50000, 60000, 45000, 70000]
}
df = pd.DataFrame(data)
n_largest = df['Salary'].nlargest(2)
print("2 Largest Salaries:")
print(n_largest)
n_smallest = df['Age'].nsmallest(2)
print("\n2 Smallest Ages:")
print(n_smallest)
