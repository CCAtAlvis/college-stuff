#if else
x<-5
if(x %% 2 == 0 ) {
  print("the number is even")
} else {
  print("the number is odd")
}

num = as.integer(readline(prompt = "enter a number :"))
#readline() is used to read user input from console
#prompt="<text>" print the text as prompt to read line

v <- c(5,534.4,87,63,2,978,2,978)

#which.max returns the index of first occurance max element
#which.min returns the index of first occurance min element

if(is.integer(v)) {
  print( v[which.max(v)] )
  print( v[which.min(v)] )
} else if (is.numeric(v)) {
  print("converting to integer")
  v <- as.integer(v)
  print( v[which.max(v)] )
  print( v[which.min(v)] )
} else {
  print("cannot find min max")
}

for(i in 1:5) {
  print(i)
}


x<-c(23,5,23,21,67,5,323,4,36,432)
even<-0
odd<-0
for(i in x) {
  if(i %% 2 == 0)
    even = even + 1
  else
    odd = odd + 1
}

print(even)
print(odd)


i<-0
while ( i < 10) {
  print(i)
  i<-i+1
}

i<-0
repeat {
  print(i)
  i<-i+1
  if ( i == 10)
    break
}


#question 1: star wars total earning
#question 2: is.numeric if...else if...else
#question 3: check if the user entered number is prime
#question 4: factorial using function

num<-as.integer(readline(prompt = "enter a number "))
flag<-TRUE

if(num<2) {
  print("not prime")
} else {
  i<-2
  while (i*i < num) {
    #i<-as.integer(i)
    if(num %% i == 0) {
      flag<-FALSE
      break;
    }
    i<-i+1
  }

  if(flag) {
    print("number is prime")
  } else {
    print("number is not prime")
  }
}


#####
# INBULT FUNCTIONS
#####

x<-c(60,65,70,76,62,0,69,70,100)
plot(x)
mean(x)
median(x)

mean(x, trim=0.1)
# outliers
# these are the extrem values
# these values affect the graph and mean etc. but are of no use
# for stasticial purposes, so we ignore these value
# trim is the factor by which we have to trim the extreme

x<-c(60,65,70,76,62,0,69,70,100, NA)
# mean(x)
# [1] NA
# so to remove NA use na.rm=TURE
mean(c, trim = 0.1, na.rm = TURE)

#user defined function
mode <- function(v) {
  uniqv <- unique(v) #returns a vector of unique values
  uniqv[which.max(tabulate(match(v, uniqv)))]
}

mode(x)
#or
x<-mode(x)
print(x)


fact <- function(x) {
  if(x == 1)
    return(1)
  else
    return(x*fact(x-1))
}

fact(170)