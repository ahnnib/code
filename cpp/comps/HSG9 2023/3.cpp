#include <iostream>

#define int long long

bool prime(int n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

std::string tostring(int n)
{
    std::string s;
    while (n)
        s = char(n % 10 + 48) + s,
        n /= 10;
    return s;
}

bool palin(std::string s)
{
    for (int i = 0; i < s.size() / 2; i++)
        if (s[i] != s[s.size()-i-1]) return 0;
    return 1;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
        #define task "NTDX"
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    // for (int i = 0; i < 100000; i++)
    //     if (prime(i) && palin(tostring(i))) cout << i << ' ';

    int X;
    std::cin >> X;
    int ans = 0;
    for (int i = 11; i < X; i++)
    {
        if (prime(i) && palin(tostring(i))) ans++;
    }
    std::cout << ans;
}
/*
11 101 131 151 181 191 313 353 373 383 727 757 787 797 919 929 10301 10501 10601 11311 11411 12421 12721 12821 13331 13831 13931 14341 14741 15451 15551 16061 16361 16561 16661 17471 17971 18181 18481 19391 19891 19991 30103 30203 30403 30703 30803 31013 31513 32323 32423 33533 34543 34843 35053 35153 35353 35753 36263 36563 37273 37573 38083 38183 38783 39293 70207 70507 70607 71317 71917 72227 72727 73037 73237 73637 74047 74747 75557 76367 76667 77377 77477 77977 78487 78787 78887 79397 79697 79997 90709 91019 93139 93239 93739 94049 94349 94649 94849 94949 95959 96269 96469 96769 97379 97579 97879 98389 98689
*/