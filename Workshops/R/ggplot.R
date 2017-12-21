library("ggplot2")

ggplot(mtcars, aes(x = mtcars$mpg)) + geom_histogram()

#defining binwidth (large bins)
ggplot(mtcars, aes(x = mtcars$mpg)) + geom_histogram(binwidth = 0.2)
#thickness of bars of histogram

#geom_density
ggplot(mtcars, aes(x = mtcars$mpg)) + geom_density(fill = "darkgrey")
#for creating a cont. line graph filled with "fill" color

#violin graph
p <- ggplot(mpg, aes(x = factor(cyl), y = hwy, fill = factor(cyl)))
p + geom_violin(scale = "width")

p + geom_violin(scale = "width") + geom_point(size = 2, position = "jitter")



######
#  SCATTER PLOT
#####

midwest
names(midwest)
dim(midwest)

gg <- ggplot(midwest, aes(x=area, y=poptotal)) +
      geom_point(aes(col=state, size=popdensity)) +
      geom_smooth(method="loess", se=F) + 
      xlim(c(0, 0.1)) + ylim(c(0, 500000)) + 
      labs(subtitle="Area Vs Population", y="Population", x="Area",
           title="Scatterplot", caption = "Source: midwest")

plot(gg)

