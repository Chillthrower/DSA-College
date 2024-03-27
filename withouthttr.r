library(rvest)

url <- "https://coinmarketcap.com/coins/"

response <- tryCatch(read_html(url), error = function(e) e)

if (!inherits(response, "error")) {
  html_content <- response
  
  coins <- html_nodes(html_content, xpath = "/html/body/div[1]/div[2]/div[1]/div[2]/div/div[1]/div[4]/table/tbody/tr/td[4]") %>%
    html_text()
  
  print(coins)
} else {
  cat("Failed to connect to the website. Please check your internet connection or the URL.\n")
