from Students.Student import Student

class StudentIT(Student):
    # Lớp StudentIT kế thừa lớp Student
    # giờ chỉ cần viết thêm thuộc tính và phương thức
    # name, age là thuộc tính của lớp cha
    def __init__(self, name, age, IT_skill):
        # Python không bắt buộc gọi dòng này trước tiên trước khi đặt các thuộc tính của lớp con
        # Tuy nhiên vẫn nên gọi dòng này trước để tránh rủi ro
        super().__init__(name, age)

        self.IT_skill = IT_skill

        # Dùng làm ví dụ cho tính liên kết
        self.certifications = []


    def add_certification(self, certification):
        self.certifications.append(certification)

    # Python có thể nạp chồng phương thức (OVERLOADING) giống như Java
    # Nếu như ở dưới đây không có study() thì Python sẽ gọi đến study() của lớp cha gần nhất
    # Muốn gọi đến phương thức của cha, dùng super().<tên phương thức>
    # ở chỗ khác, dùng <tên lớp cha>.<tên phương thức>(<đối tượng>) (xem main.py:25)
    def study(self):
        print(f"{self.name} is coding {self.IT_skill}...")