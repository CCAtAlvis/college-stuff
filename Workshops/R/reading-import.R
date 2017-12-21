#####
# CSV
#####
#first install the library of the containing package
pools <- read.csv("data2-data/Swimming_pools.csv")
#now to read csv use raed.csv

#
#View(pools)
#to view proper csv in another window
#

#
#class(pools)
#data.frames
#

str(pools)
#this converts the data into string, showing some smaple data
#but a the time of loading i.e. read.csv(), R converts the char data
#to integer so increase speed (by hashing)
#to avoid this use StringAsFactor=FALSE

pools <- read.csv("data2-data/Swimming_pools.csv", stringsAsFactors = FALSE)
str(pools)


ex1 <- read.csv("data2-data/Ex1.csv")
class(ex1)
dim(ex1)
names(ex1)

ex1_salary <- ex1$salary
ex1_salary
max(ex1_salary)
min(ex1_salary)
mean(ex1_salary)
median(ex1_salary)

#print
ex1[which.max(ex1[,3]), 2:3]
#
#   name salary
# 5 Gary 843.25
#


#####
# XLSX
#####
#library to read excel data
library("readxl")

#this is just to load the data into R workspace
excel_sheets("data2-data/Criteria 2.xlsx")

#this loads the data into R object to use
year1 <- read_excel("data2-data/Criteria 2.xlsx", sheet = 1)
class(year1)

year2 <- read_excel("data2-data/Criteria 2.xlsx", sheet = 2)

year_list <- list(year1, year2)
year_list


#####
# Loading from URL
#####
url <- 'http://s3.amazonaws.com/assets.datacamp.com/production/course_1294/datasets/sales.csv'
#read.csv can also download data from the internet sources

url_data <- read.csv(url, stringsAsFactors = FALSE)
dim(url_data)


#####
# XML
#####

#lets load the libraries
library("XML")
library("method")

xml_data <- xmlParse("data2-data/Records.xml")
xml_data

xml_root <- xmlRoot(xml_data)
xml_root

xml_size <- xmlSize(xml_root)
xml_size

#
#print(xml_root[3])
#

xml_dataframe <- xmlToDataFrame(xml_data)
xml_dataframe
