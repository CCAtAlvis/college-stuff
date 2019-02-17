class Emp:
    count = 0

    def __init__ (self):
        print("creating new employee")
        self.name = input("enter name: ")
        self.salary = int(input("enter salayr: "))
        print("created new employee \n")
        Emp.count += 1

    def displayInfo (self):
        print("Name: %s     Salary: %d" %(self.name, self.salary))

    def displayCount ():
        print("Employee count:", Emp.count)

e1 = Emp()
e2 = Emp()

e1.displayInfo()
e2.displayInfo()
e1.displayCount()
