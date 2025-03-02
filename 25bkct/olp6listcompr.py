# Returns a list version of the original lst
def process_lst(lst):
    if ".." in lst:
        lst = lst[1:-1].split("..")
        return list(range(int(lst[0]), int(lst[1]) + 1))
    else:
        lst = lst[1:-1].split(',')
        return [int(x) for x in lst]

# Returns value of function f(x)
def calc(f, x):
    f = f.replace("i", str(x))
    f = f.replace("j", str(x))

    f += '+'
    res = 0
    num = ""
    op = "+"
    for i in f:
        if i in ['+', '-', '*']:
            num = int(num)
            if (op == '+'): res += num
            if (op == '-'): res -= num
            if (op == '*'): res *= num
            num = ""
            op = i
        else:
            num += i

    return res



cmd = input()

lst = cmd.split()

fx = lst[0][2:-1]
fy = lst[1][:-1]
lst_x = process_lst(lst[5][:-1])
lst_y = process_lst(lst[8][:-1])

# print(calc(fx, 16))
# print(fx, fy, lst_x, lst_y)

ans = []
for x in lst_x:
    for y in lst_y:
        ans.append((calc(fx, x), calc(fy, y)))


print("[" + ", ".join(f"({a},{b})" for a, b in ans) + "]")