library(dplyr)

merged_data <- merge(read.csv("sales.csv"), read.csv("salary.csv"), by = "ID")

merged_data

agg_data <- merged_data %>% group_by(Gender) %>% summarise(tut_sal = sum(Salary), avg_age = mean(Age), count = n())

agg_data

filt_data <- merged_data %>% filter(Age > 15)

filt_data

tran_data <- merged_data %>% mutate(doub_sal = Salary * 2, sen = ifelse(Age > 25, "Sen", "Jun"))

tran_data

merged_data1 <- merge(read.csv("sales_new.csv"), read.csv("customer.csv"), by = "Name")

merged_data1

merged_data1 <- merged_data1 %>% mutate(tut_sale = Quantity * Price)

merged_data1

sales_by_count <- merged_data1 %>% group_by(Country) %>% summarise(tut_sale = sum(tut_sale))

sales_by_count

filt_usa <- merged_data1 %>% filter(Country == "USA")

filt_usa
