class Student:
    # Hàm khởi tạo thuộc tính mặc định
    # self: đại diện cho lớp hiện tại
    def __init__(self, name=None, age=None):
        self.name = name
        self.age = age

        # Tính liên kết (ASSOCIATION)
        # Một đối tượng có thể liên kết với đối tượng khác
        self.friends = []


    # Tương tự hàm toString trong Java
    # hoặc dùng __repr__
    def __str__(self):
        return f"{self.name} {self.age}"


    # Các phương thức của đối tượng
    def study(self):
        print(f"{self.name} is Studying...")

    # Phương thức thể hiện tính liên kết (ASSOCIATION)
    # friend là 1 đối tượng khác
    def add_friend(self, friend):
        self.friends.append(friend)

    def list_friends(self):
        if not self.friends:
            print("None")
        for friend in self.friends:
            print(friend.name)