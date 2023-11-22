import pandas as pd

data = {
    'Name': ['Alice', 'Bob', 'Charlie', 'David', 'Eve'],
    'Age': [25, 30, 35, 40, 22],
    'City': ['New York', 'San Francisco', 'Los Angeles', 'Chicago', 'Miami']
}

df = pd.DataFrame(data)
series = pd.Series(data)
df['Salary'] = [1, 2, 3, 4, 5] #Adding columns
print(series[0])
print(series['Age'])
df.drop('Age', axis = 1, inplace=True)  #Removing columns
print(df.loc[1]) #Locating Row
df.drop(2, inplace= True) #Deleting Row
print(pd.concat([df, pd.DataFrame([pd.Series(['Sarvajith', 'Manglore', 10], index = ['Name', 'City', 'Salary'])], columns=df.columns)], ignore_index=True)) #Adding Row
