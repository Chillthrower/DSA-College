import pandas as pd

titanic_data = pd.read_csv('titanic.csv')

print("First 5 rows of the Titanic dataset:")
print(titanic_data.head())

summary_stats = titanic_data.describe()
print("\nSummary Statistics:")
print(summary_stats)

survived_passengers = titanic_data[titanic_data['Survived'] == 1]
print("\nPassengers who survived:")
print(survived_passengers.head())

first_class_passengers = titanic_data[titanic_data['Pclass'] == 1]
print("\nPassengers in First Class:")
print(first_class_passengers.head())

mean_age_by_class = titanic_data.groupby("Pclass")['Age'].mean()
print("\nMean Age by Class:")
print(mean_age_by_class)

sorted_by_age = titanic_data.sort_values(by='Age', ascending=False)
print("\nPassengers sorted by Age (Descending):")
print(sorted_by_age.head())

passenger_count_by_class = titanic_data['Pclass'].value_counts()
print("\nPassenger Count by Class:")
print(passenger_count_by_class)

correlation = titanic_data['Fare'].corr(titanic_data['Age'])
print("\nCorrelation between Fare and Age:", correlation)
