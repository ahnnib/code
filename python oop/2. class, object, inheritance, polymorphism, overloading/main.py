from Students.Student import Student
from StudentIT.StudentIT import StudentIT

# s = Student("asd", 13)
# s.age = s.age + 1
# print(s) # --> 14

# print(object.__str__(s))
# print(object.__repr__(s))

# s1 = Student("candy")
# s2 = Student("cookie")
# s3 = Student("milk")

# s1.add_friend(s2)

# print("Friends of s1:") # --> cookie
# s1.list_friends()
# print("Friends of s2:") # --> None
# s2.list_friends()

# s = StudentIT("Coder", 15, "Python")
# s.study() # --> Coder is coding Python...

# Nếu như muốn gọi phương thức của cha
# Student.study(s) # --> Coder is Studying...

# Trong Java, các kiểu dữ liệu như int, bool... là kiểu dữ liệu nguyên thủy (PRIMITIVE TYPES)
# Khác với Python, mọi thứ đều là OBJECT
# ví dụ: x = 4; type(x) --> <class 'int'>

# Student s = new StudentIT() tương đương với s: Student = StudentIT()

# VARIABLE SHADOWING
class Student:
    def __init__(self, name):
        self.name = name
        name = "TRE"

student1 = Student("Trau")
print(student1.name) # --> "Trau"
# biến name = "TRE" hoàn toàn độc lập với "name" trong tham số
# Một khi tham số đã bị đè, sẽ không có cách nào truy cập nó ở trong vùng bị đè bởi biến
# Nếu muốn giữ tham số và biến, cần dùng tên biến khác


# Comparison Between .format() and f-Strings
# Feature	.format()	f-Strings
# Introduced	Python 2.7 and Python 3.x	Python 3.6 and newer
# Expression Support	Expressions (like ternary operators) must be inside .format()	Expressions can be written directly inside the string ({})
# Readability	Slightly longer and less readable	Cleaner and shorter for embedding expressions





### Bài tập vận dụng
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def introduce(self):
        print(f"Hi, I'm {self.name}. I'm {self.age} years old.")

    def greet(self, other_person):
        print(f"Hi, {other_person.name}! I'm {self.name}. Nice to meet you!")


def compare_age(person1, person2):
    result = "{} is {} than {}".format(
        person1.name,
        # TERNARY OPERATOR
        # SYNTAX: value_if_true if condition else value_if_false
        "older" if person1.age > person2.age
        else "younger" if person1.age < person2.age
        else "the same age as",
        person2.name
    )

    # better readability choice

    # result = "{name1} is {relation} than {name2}".format(
    #     name1=person1.name,
    #     relation="older" if person1.age > person2.age else "younger" if person1.age < person2.age else "the same age as",
    #     name2=person2.name
    # )

    # relation = "older" if ...
    # print(f"{person.name1} is {relation} {person.name2}")

    # result = f"{person1.name} is {'older' if person1.age > person2.age else 'younger' if person1.age < person2.age else 'the same age as'} {person2.name}"

    print(result)


trau = Person("Trau", 11)
william = Person("William", 13)

trau.greet(william)
william.greet(trau)

compare_age(trau, william)
compare_age(william, trau)

print("---")


class Student(Person):
    def __init__(self, name, age, school):
        super().__init__(name, age)
        self.school = school

    def greet_teacher(self, teacher):
        print(f"Hi, teacher {teacher.name}! I'm studying at {self.school} school.")

class Teacher(Person):
    def __init__(self, name, age, school):
        super().__init__(name, age)
        self.school = school

    def greet_student(self, student):
        print(f"Hi, student {student.name}! I'm teaching at {self.school} school.")


teacher1 = Teacher("Quang", 30, "Nguyen Trai")
teacher2 = Teacher("Mai", 35, "Nguyen Khuyen")

student1 = Student("Hoa", 12, "Dang Tran Con")
student2 = Student("Hong", 15, "Nguyen Trai")

teacher1.introduce()
teacher1.greet(teacher2)
teacher1.greet_student(student1)

student1.introduce()
student1.greet(student2)
student1.greet_teacher(teacher1)
### Output
"""
Trau
Hi, William! I'm Trau. Nice to meet you!
Hi, Trau! I'm William. Nice to meet you!
Trau is younger than William
William is older than Trau
---
Hi, I'm Quang. I'm 30 years old.
Hi, Mai! I'm Quang. Nice to meet you!
Hi, student Hoa! I'm teaching at Nguyen Trai school.
Hi, I'm Hoa. I'm 12 years old.
Hi, Hong! I'm Hoa. Nice to meet you!
Hi, teacher Quang! I'm studying at Dang Tran Con school.
"""