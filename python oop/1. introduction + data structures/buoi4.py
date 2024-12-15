import random

def group_by_city(applicants):
    # hoc sinh lam bai tai day
    city_groups = {}
    for applicant in applicants:
        name, city = applicant.split(",")
        if not city in city_groups:
            city_groups[city] = []
        city_groups[city].append(name)

    return city_groups

def get_random_from_each_city(applicants):
    # hoc sinh lam bai tai day
    grouped_applicants = group_by_city(applicants)
    list = {}
    for city in grouped_applicants:
        student_list = grouped_applicants[city]
        list[city] = []
        random_student = random.choice(student_list)
        list[city].append(random_student)
    return list

applicants = ["Hoa,Ha Noi", "Thuy,Ho Chi Minh", "Thao,Nam Dinh", "Dung,Ha Noi", "Manh,Ha Noi", "Van,Ho Chi Minh"]
# grouped_applicants = group_by_city(applicants)
# print(grouped_applicants)

result = get_random_from_each_city(applicants)
print(result)
result = get_random_from_each_city(applicants)
print(result)
