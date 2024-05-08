library(ggplot2)
library(dplyr)
library(plotly)

titanic_data = read.csv("train.csv")

sum(is.na(titanic_data))
summary(titanic_data)

# titanic_data <- na.omit(titanic_data)

titanic_data$Age[is.na(titanic_data$Age)] <- mean(titanic_data$Age, na.rm = TRUE)

missing_values <- colSums(is.na(data))
print(missing_values)

adult_passengers <- filter(data, Age > 18)
sorted_titanic <- arrange(data, desc(Fare))

t_test_result <- t.test(Age ~ Survived, data = data)
correlation_coefficient <- cor(data$Age, data$Fare)

print(titanic_data)
lm_model <- lm(PassengerId~ Pclass, data = titanic_data)
print(lm_model)
print(coef(lm_model))
print(coef(lm_model)[1])

summary(lm_model)

regression_line <- ggplot(titanic_data ,aes(x = PassengerId, y = Pclass)) + geom_point() + geom_smooth(method = "lm", se = FALSE, color = "blue") + ggtitle("cool") + xlab("PassengerId") + ylab("pClass") + theme_minimal()

regression_line

residual_line <- ggplot(titanic_data, aes(x = fitted(lm_model), y = residuals(lm_model))) + geom_point() + geom_hline(yintercept = 0, linetype = "dashed", color = "red") +   ggtitle("Residuals Plot") + xlab("Fitted values") + ylab("Residuals") + theme_minimal()

residual_line

histogram <- ggplot(titanic_data, aes(x = Age)) + geom_histogram(bandwidth = 5, fill = "blue", color = "black") + labs(title = "cool", x = "Age", y = "Frequency")

histogram

titanic_data$Survived <- factor(titanic_data$Survived, levels = c("0", "1"))

bar_graph <- ggplot(titanic_data, aes(x = factor(Pclass), fill = factor(Survived))) + geom_bar(position = "dodge") + labs(title = "cool1", x = "Passenger Class", y = "Count", fill = "Survived") + scale_fill_manual(values = c("0" = "red", "1" = "blue"))

bar_graph

line_plot <- ggplot(titanic_data, aes(x = Age, y = ..density..)) + geom_density(fill = "blue", alpha = 0.5) + labs(title = "cool", x = "Age", y = "Density")

line_plot

scatter_plot <- ggplot(titanic_data, aes(x = Age, y = Fare, color = factor(Survived))) + geom_point() + labs(title = "cool", x = "Age", y = "Fare", color = "Survived") + scale_color_manual(values = c("0" = "red", "1" = "blue"))

scatter_plot

heat_map <- ggplot(titanic_data, aes(x = Pclass, y = Survived)) + stat_bin_2d(bins = 10, aes(fill = ..count..)) + labs(title = "coool", x = "Pclass", y = "Survived", fill = "Frequency") + scale_fill_continuous(name = "Frequency", low = "white", high = "blue")

heat_map

box_plot <- boxplot(Age ~ Survived, data = data, col = c("red", "blue"), main = "Boxplot of Age by Survived")

box_plot

ggsave("bar_plot_cool_1.png", plot = bar_graph, width = 8, height = 6)

htmlwidgets::saveWidget(ggplotly(bar_graph), "bar_graph_daddy.html", selfcontained = TRUE)
