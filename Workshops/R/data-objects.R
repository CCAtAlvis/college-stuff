#####
# VECTORS
#####

v<-c(1, 4, 7, 8) #create a vector named "v" and
                 #c to combine the data
print(v)
class(v)

v<-c('a', 'b')
v<-c(3, 'a', 4-3i, 4.1) #class of v will be char
#this is because vector can only have single datatype
#so all other datatypes are demoted to the least datatype
#TO CHECK: datatype precedence

print(v[3])
#INDEXING STARTS FROM 1 NOOOOOOOOOOOOOOOO

#combining vectors
n<-1
s<-c(3, 7)
ns<-c(n, s)

n<-c(4, 76, 'c')
s<-c(3, 7)
ns<-c(n, s)

n<-c(4, 76, 'c')
s<-c(3, 7)
ns<-c(n, s, 5)

#arithmetics
#for arithmetics length of every vector should be same
s<-c(1, 2, 3)
p<-c(10, 20, 30)

s+p
s-p
s*p
p/s

#or length of second vector should be multiple of first vector 
m<-c(10, 20, 30, 40, 50, 60) #cool will do

#####
# m<-c(10, 20, 30, 40, 50) #nope
# In p + m : longer object length is not a multiple of shorter object length
#####

p+m

m[3] #print the 3rd element
m[-3] #print except 3rd element
m[2:6] #print from 2nd till 6th element
m[c(1, 3, 9)] #print these specific elements

#####
# m[c(1, 3, -3)] #print these specific elements
# Error in m[c(1, 3, -3)] : only 0's may be mixed with negative subscripts
#####

#Named vectors
p<-c(1, 2, 3)
names(p)<-c("a", "b", "c")
p
p["b"]


#####
# LIST
#####

l<-list(1,2,3) #list() is used to create list datatype
print(l)
#[[1]]
#[1] 1
#
#[[2]]
#[1] 2

#[[3]]
#[1] 3

#this means list is kindof 2d array
#the first index [[1]] specifies the index with refrence to list
#the next [1] index is the index  with reference to the index

class(l)
#class of the list is "list" that means you can store any datatype inside list
#that means even list, vectors, num etc...

lis<-list(l, m, 1, 4, 'f')
lis

named_list<-list(x=c(1,2,3), y=c('1','2','3')) #this creates a list
names(named_list) #provides the names of variables inside it
named_list$x #prints all the data of a particular variable 

named_list<-list(x=c(1,2,3), y=c('1','2','3'), z=list(l, lis, m))
names(named_list)
named_list$z

#####
# MARTIX
#####
#by default data is inserted col wise i.e. col1 then col2 then...
M<-matrix(1:6, nrow = 3, ncol = 2)
M

M<-matrix(1:6, nrow = 2, ncol = 3)
M

#to insert data row wise add byrow=TRUE
M<-matrix(1:6, nrow = 2, ncol = 6, byrow=TRUE)
M

#####
#M<-matrix(1:6, nrow = 2, ncol = 4, byrow=TRUE)
#Warning message:
#In matrix(1:6, nrow = 2, ncol = 4, byrow = TRUE) :
#data length [6] is not a sub-multiple or multiple of the number of columns [4]
#####

#print is row, col
M[1,2]


#box office collection 
new_hope<-c(323.313, 233.434)
empire_strikes<-c(324.323, 546.21)
return_jedi<-c(145.566, 745.21)

#create box_office
box_office<-c(new_hope, empire_strikes, return_jedi)

#construct star_wars_matrix
star_war_matrix<-matrix(box_office, byrow = TRUE, nrow = 3)
star_war_matrix
#####
#         [,1]    [,2]
# [1,] 323.313 233.434
# [2,] 324.323 546.210
# [3,] 145.566 745.210
#####

#naming martix
region<-c("US", "non-US")
titles<-c("a new hope", "the empire", "return jedi")

#name the columns with region
colnames(star_war_matrix)<-region

#now name the rows with movie title
rownames(star_war_matrix)<-titles

star_war_matrix
#####
#                 US  non-US
#a new hope  323.313 233.434
#the empire  324.323 546.210
#return jedi 145.566 745.210
#####


#get summation of rows
collection<-rowSums(star_war_matrix)
collection

#####
# a new hope  the empire return jedi 
#    556.747     870.533     890.776 
#####

# cbind is used to add new col to a matrix
# i.e. binding new matrix rows to existing martix
# there should be same no of rows to bind coll
all<-cbind(star_war_matrix, collection)
all

the_phantom_menace<-c(234.43, 452.54)
attack_of_the_clones<-c(351.21, 435.53)
revenge_of_the_sith<-c(543.23, 352.34)

box_office2<-c(the_phantom_menace, attack_of_the_clones, revenge_of_the_sith)

star_war_matrix2<-matrix(box_office, byrow = TRUE, nrow = 3)
titles<-c("the phantom menace", "attack of the clones", "revenge of the sith")
rownames(star_war_matrix2)<-titles

# rbind is used to add new rows to the matrix,
# i.e. binding new matrix rows to existing martix
# there should be same no. or cols to bind rows
all_wars_matrix<-rbind(star_war_matrix, star_war_matrix2)
all_wars_matrix

collection<-colSums(all_wars_matrix)
all_wars_matrix<-rbind(all_wars_matrix, collection)
all_wars_matrix


#####
# DATA FRAMES
#####

n = c(2, 3, 5)
s = c("a", "b", "c")
b = c(TRUE, FALSE, FALSE)
df = data.frame(n, s, b)
df
class(df)


#####
# DATA SETS
#####
datasets::mtcars #print the whole damn dataset
class(mtcars) #get the class of dataset, here it is data.frames
dim(mtcars) #get dimensions of the dataset, rows x cols 
names(mtcars) #get names of colms 
mtcars$mpg #print a particular col
head(mtcars, n=10) #get top n rows, default is 6 rows
tail(mtcars, n=10) #get bottom n rows, default is 6 rows

#####
#                      mpg cyl  disp  hp drat    wt  qsec vs am gear carb
# Mazda RX4           21.0   6 160.0 110 3.90 2.620 16.46  0  1    4    4
# Mazda RX4 Wag       21.0   6 160.0 110 3.90 2.875 17.02  0  1    4    4
# Datsun 710          22.8   4 108.0  93 3.85 2.320 18.61  1  1    4    1
# Hornet 4 Drive      21.4   6 258.0 110 3.08 3.215 19.44  1  0    3    1
# Hornet Sportabout   18.7   8 360.0 175 3.15 3.440 17.02  0  0    3    2
# Valiant             18.1   6 225.0 105 2.76 3.460 20.22  1  0    3    1
# Duster 360          14.3   8 360.0 245 3.21 3.570 15.84  0  0    3    4
# Merc 240D           24.4   4 146.7  62 3.69 3.190 20.00  1  0    4    2
# Merc 230            22.8   4 140.8  95 3.92 3.150 22.90  1  0    4    2
# Merc 280            19.2   6 167.6 123 3.92 3.440 18.30  1  0    4    4
# Merc 280C           17.8   6 167.6 123 3.92 3.440 18.90  1  0    4    4
# Merc 450SE          16.4   8 275.8 180 3.07 4.070 17.40  0  0    3    3
# Merc 450SL          17.3   8 275.8 180 3.07 3.730 17.60  0  0    3    3
# Merc 450SLC         15.2   8 275.8 180 3.07 3.780 18.00  0  0    3    3
# Cadillac Fleetwood  10.4   8 472.0 205 2.93 5.250 17.98  0  0    3    4
# Lincoln Continental 10.4   8 460.0 215 3.00 5.424 17.82  0  0    3    4
# Chrysler Imperial   14.7   8 440.0 230 3.23 5.345 17.42  0  0    3    4
# Fiat 128            32.4   4  78.7  66 4.08 2.200 19.47  1  1    4    1
# Honda Civic         30.4   4  75.7  52 4.93 1.615 18.52  1  1    4    2
# Toyota Corolla      33.9   4  71.1  65 4.22 1.835 19.90  1  1    4    1
# Toyota Corona       21.5   4 120.1  97 3.70 2.465 20.01  1  0    3    1
# Dodge Challenger    15.5   8 318.0 150 2.76 3.520 16.87  0  0    3    2
# AMC Javelin         15.2   8 304.0 150 3.15 3.435 17.30  0  0    3    2
# Camaro Z28          13.3   8 350.0 245 3.73 3.840 15.41  0  0    3    4
# Pontiac Firebird    19.2   8 400.0 175 3.08 3.845 17.05  0  0    3    2
# Fiat X1-9           27.3   4  79.0  66 4.08 1.935 18.90  1  1    4    1
# Porsche 914-2       26.0   4 120.3  91 4.43 2.140 16.70  0  1    5    2
# Lotus Europa        30.4   4  95.1 113 3.77 1.513 16.90  1  1    5    2
# Ford Pantera L      15.8   8 351.0 264 4.22 3.170 14.50  0  1    5    4
# Ferrari Dino        19.7   6 145.0 175 3.62 2.770 15.50  0  1    5    6
# Maserati Bora       15.0   8 301.0 335 3.54 3.570 14.60  0  1    5    8
# Volvo 142E          21.4   4 121.0 109 4.11 2.780 18.60  1  1    4    2
#####
