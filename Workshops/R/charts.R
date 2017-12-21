library(MASS)

plot(whiteside)

#xlab is used to give lable to x axis
#ylab is used to give lable to y axis
plot(whiteside$Temp, whiteside$Gas,
     xlab = "Temperature",
     ylab = "heating gas consumption" )

plot(whiteside$Insul)
plot(whiteside$Temp)
plot(whiteside$Gas)

#pch is for different types points graphics
#col is used to give color to points on graph
plot(Cars93$Price, Cars93$Max.Price, pch=16, col="red")

points(Cars93$Price, Cars93$Min.Price, pch=17, col="blue")

abline(a=0, b=1, lty=1, lwd=1)
dev.off()


#####
# PLOTING MULTIPLE GRAPHS SIDE BY SIDE
#####

par(mfrow = c(1,2))
plot(Animals$body, Animals$brain)
title("bla plot")

plot(Animals$body, Animals$brain, log = "xy")
title("log plot")


#####
# PIE CHARTS
#####
tbl <- sort(table(mtcars$mpg), decreasing = FALSE)
pie(tbl)


#####
# BAR CHARTS
#####
barplot(table(mtcars$mpg), las = 1, cex.names = 1)


#####
# HISTOGRAM
#####

hist(cars$speed, main = "hist() plot")
title("Histogram")
#main=""  is same as title
dev.off()


##########
plot(Animals$brain, type = "s")
##########

index3 <- which(Cars93$Cylinders == 3)
index3

plot(Cars93$Horsepower, Cars93$MPG.city, pch = 1)
text(x = Cars93$Horsepower[index3],
     y = Cars93$MPG.city[index3],
     labels = Cars93$Make[index3],
     adj = -0.1, col = "red")
