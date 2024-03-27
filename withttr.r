library(rvest)
library(xml2)
library(httr)

response <- tryCatch(GET("https://coinmarketcap.com/coins/"), error = function(e) e)
if(!inherits(response, "error"))
{
  html_content <- read_html(response$content, encoding = "UTF-8")
  
  coins <- html_content %>%
    html_nodes(xpath = "/html/body/div[1]/div[2]/div[1]/div[2]/div/div[1]/div[4]/table/tbody/tr/td[3]") %>%
    html_text()
  
  print(coins)
}
