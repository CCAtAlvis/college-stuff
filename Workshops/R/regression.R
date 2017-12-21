#####
# REGRESSION
#####

x<-c(20,16,19.79999924,18.39999962,17.10000038,15.5,14.69999981,17.10000038,15.39999962,16.20000076,15,17.20000076,16,17,14.39999962)
y<-c(88.59999847,71.59999847,93.30000305,84.30000305,80.59999847,75.19999695,69.69999695,82,69.40000153,83.30000305,79.59999847,82.59999847,80.59999847,83.5,76.30000305)

plot(x, y)


#building a linear model for a dat set 
#lm() builds a linear model i.e. linear regression

linear_regression <- lm(y~x)
#class(linear_regression) is of class lm
plot(linear_regression)


summary(linear_regression)

#coef gives the coefficient of the dependent variables
#also the intercept
coef(linear_regression)


#####
# MULTIPLE LINEAR REGRESSION
#####
#using mtcars as the dataset
dim(mtcars)

input <- mtcars[, c("mpg","disp","hp","wt")]

#creating the model
model <- lm(mpg~disp+hp+wt, data = input)
#this modle is a lnear regression with mulitple variables
#i.e. multiple linear regression

plot(model)

#to get coef of a particular variable or intercept 
coef(model)[1]

i <- coef(model)[1]
a <- coef(model)[2]
b <- coef(model)[3]
c <- coef(model)[4]
  
x1 <- -1000
x2 <- 21
x3 <- 1

y <- i + a*x1 + b*x2 + c*x3
y
