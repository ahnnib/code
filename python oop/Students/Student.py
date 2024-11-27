class Student:
    # Hàm khởi tạo thuộc tính mặc định
    # self: đại diện cho lớp hiện tại
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # Các phương thức của đối tượng
    def say_hello():
        print("Hello, my name is {name} and I'm {age} years old.".format(self.name, self.age))