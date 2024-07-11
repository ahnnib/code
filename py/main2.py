from math import factorial as f
def ckn(n, k):
    return f(n) / (f(k) * f(n - k))

print(ckn(10, 4))