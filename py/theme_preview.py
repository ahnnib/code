if __name__ == '__main__':
    import math
    from numbers import *

    class Car:
        def __init__(self, brand, year):
            self.brand = brand
            self.year = year

    if 1 + 1 == 2:
        print(math.sqrt(49))

    car1 = Car("Mustang", 1968)
    car2 = Car("Koenisegg", 2019)

    print(car1.brand, car1.year, end=' ')
    print()
    print(car2.brand, car2.year, end=' ')
