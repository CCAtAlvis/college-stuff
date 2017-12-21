#####
# Q PLOT
#####

library("ggplot2")

iris
names(iris)
head(iris)

qplot(Sepal.Length, Petal.Length, data = iris)

qplot(Sepal.Length, Petal.Length, data = iris, color = Species)

qplot(Sepal.Length, Petal.Length, data = iris,
      color = Species, size = Petal.Width)

qplot(Sepal.Length, Petal.Length, data = iris,
      color = Species, size = Petal.Width,
      xlab = "sepal length",
      ylab = "petal length",
      main = "Sepal vs. Petal Length in (Fisher's) Iris data")


# gemo
qplot(gear, mpg, data = mtcars,
      geom = c("boxplot", "jitter"),
      fill = gear, main = "some random text",
      xlab = "", ylab = "miles/gallon")


qplot(gear, mpg, data = mtcars,
      geom = c("point"),
      fill = gear, main = "some random text",
      xlab = "", ylab = "miles/gallon")
