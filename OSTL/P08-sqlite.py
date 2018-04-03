import sqlite3

db = sqlite3.connect("student.db")
cursor = db.cursor()

# cursor.execute("drop table student;")

cursor.execute('''create table if not exists student(
                id Integer primary key,
                name Text,
                course Text);''')

cursor.execute("insert into student values(3, 'ankita', 'CE');")
# cursor.fetchall()

cursor.execute("select * from student")
rows = cursor.fetchall()

for row in rows:
    print(row)

db.commit()

# cursor.execute('''insert into student (id, name)
#                 values(?, ?);''')

# cursor.execute('''insert into student (id, name)
#                 values(?, ?);''')