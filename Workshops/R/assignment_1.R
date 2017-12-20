#question 1: star wars total earning
#question 2: is.numeric if...else if...else
#question 3: check if the user entered number is prime
#question 4: factorial using function

#####
# question 1
#####
new_hope<-c(323.313, 233.434)
empire_strikes<-c(324.323, 546.21)
return_jedi<-c(145.566, 745.21)

box_office<-c(new_hope, empire_strikes, return_jedi)
star_war_matrix<-matrix(box_office, byrow = TRUE, nrow = 3)

region<-c("US", "non-US")
titles<-c("a new hope", "the empire", "return jedi")
colnames(star_war_matrix)<-region
rownames(star_war_matrix)<-titles

the_phantom_menace<-c(234.43, 452.54)
attack_of_the_clones<-c(351.21, 435.53)
revenge_of_the_sith<-c(543.23, 352.34)

box_office2<-c(the_phantom_menace, attack_of_the_clones, revenge_of_the_sith)
star_war_matrix2<-matrix(box_office, byrow = TRUE, nrow = 3)

titles<-c("the phantom menace", "attack of the clones", "revenge of the sith")
rownames(star_war_matrix2)<-titles

all_wars_matrix<-rbind(star_war_matrix, star_war_matrix2)

movie_earning<-rowSums(all_wars_matrix)
all_wars_matrix<-cbind(all_wars_matrix, movie_earning)

collection<-colSums(all_wars_matrix)
all_wars_matrix<-rbind(all_wars_matrix, collection)
all_wars_matrix

#####
# question 2
#####
v <- c(5,534.4,87,63,2,978,2,978)

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

#####
# question 3
#####
num<-as.integer(readline(prompt = "enter a number "))
flag<-TRUE

if(num<2) {
  print("not prime")
} else {
  i<-2
  while (i*i < num) {
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
# question 4
#####
num<-as.integer(readline(prompt = "find factorial of? (less then 170)> "))

fact <- function(x) {
  if(x == 1)
    return(1)
  else
    return(x*fact(x-1))
}

fact(num)
