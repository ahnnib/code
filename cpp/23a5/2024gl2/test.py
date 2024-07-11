from math import sqrt, ceil, floor

def scp(l:int, r:int):
    return floor(sqrt(r)) - ceil(sqrt(l)) + 1

l = 1
r = 9
for _ in range(10):
    print(l, r, scp(l, r))
    l *= 10
    r = r * 10 + 9

# 1 9 3
# 10 99 6
# 100 999 22
# 1000 9999 68
# 10000 99999 217
# 100000 999999 683
# 1000000 9999999 2163
# 10000000 99999999 6837
# 100000000 999999999 21623
# 1000000000 9999999999 68377