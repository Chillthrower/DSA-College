import pandas as pd

# Create a sample DataFrame
data = {'Category': ['A', 'B', 'A', 'B', 'A', 'C'], 'Values': [10, 25, 18, 32, 15, 8]}
df = pd.DataFrame(data)

group = df.groupby('Category')
group1 = df.groupby(['Category', 'Values'])

#Sum and mean by Category
print(group['Values'].sum())
print(group['Values'].mean())

print(group1.size())

data1 = {
    'ID': [1, 2, 3, 4],
    'Name': ['Alice', 'Bob', 'Charlie', 'David']
}

data2 = {
    'ID': [1, 2, 3, 4],
    'Age': [25, 30, 22, 35]
}

df1 = pd.DataFrame(data1)
df2 = pd.DataFrame(data2)

print(df1.set_index('ID').join(df2.set_index('ID'), how='outer'))
print(pd.merge(df1, df2, on='ID', how='inner'))
print(pd.concat([df1, df2], ignore_index= True))
