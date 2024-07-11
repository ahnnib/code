def file_name_generator():

    from random import choice

    choices = [
        '0','1','2','3','4','5','6','7','8','9',

        'a','b','c','d','e','f','g','h','i','j',
        'k','l','m','n','o','p','q','r','s','t',
        'u','v','w','x','y','z',

        'A','B','C','D','E','F','G','H','I','J',
        'K','L','M','N','O','P','Q','R','S','T',
        'U','V','W','X','Y','Z'
    ]

    for i in range(int(input())):
        print(choice(choices), end='')



def reverse_string():
    print(input()[::-1])



def fraction_simplifier():
    from math import gcd

    n, d = input().split()

    n = int(n)
    d = int(d)

    print(int(n / gcd(n, d)), int(d / gcd(n, d)), end=' ')



def shuffle_string():
    from random import sample

    s = input()

    print(''.join(sample(s, len(s))))



def find_tnt_size():

    from math import sqrt

    n = int(input())

    for y in range(1, int(sqrt(n))):
        if sqrt(n / y) == int(sqrt(n / y)) and n % y == 0:
            print(int(sqrt(n / y)), y)



def find_divisor():                       # *****************NOT WORKING****************** #
    n = int(input())

    d = 1
    a = []
    while d * d <= n:
        if (n % d == 0):
            a.append(d)
            if (d != n / d): a.append(int(n / d))
        d += 1

    a.sort()
    print(len(a)); print(*a)



def find_gcd():
    from math import gcd

    ns = [int(i) for i in input().split()]

    ans = ns[0]
    for i in range(1, len(ns)):
        ans = gcd(ans, ns[i])

    print(ans)



def find_lcm():
    from math import lcm

    ns = [int(i) for i in input().split()]
    ans = lcm(ns[0], ns[1])

    for i in range(2, len(ns)):
        ans = lcm(ans, ns[i])

    print(ans)



def string_generator():
    from random import randint

    for i in range(int(input())):
        print(chr(randint(32, 126)), end='')



def auto_typing():
    from time import sleep
    sleep(1)

    import pyautogui

    dir = input()
    f = open("{}".format(dir), 'r')

    for lines in f.readlines():
        pyautogui.write(lines)
        pyautogui.press("Enter")

    f.close()



def bin_to_dec():
    print(int(input(), 2))


def dec_to_bin():
    print(bin(int(input()))[2:])


def password_generator():
    string_generator()
    shuffle_string()

def factorization():
    x = int(input())
    i = 2
    while i * i <= x:
        while x % i == 0:
            x /= i
            print(i, sep=' ')
        i += 1
    if x > 1: print(int(x))

# Y3?;CP=V#^%9XX(r>'-a/+Xy<'r)7: hUY9`MV0P}6,rlf/nj0
# find_lcm()

factorization()