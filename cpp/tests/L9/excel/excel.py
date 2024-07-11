import sys
sys.stdin = open("excel.inp", "r")
sys.stdout = open("excel.out", "w")

class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y

arr = []
q = int(input())
for _ in range(q):
    t = input().split()
    if t[1] == '=':

