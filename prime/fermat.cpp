// https://tleoj.edu.vn/problem/34c
// số Carmichael -> dùng fermat sẽ WA
// https://vnoi.info/wiki/algo/algebra/primality_check.md
// result: WA + TLE
// Go rabin miller fermat sus
#include <iostream>
#include <stdlib.h>
using namespace std;

static int k = 5; // số phép thử
long long expo(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long t = expo(a, b>>1, mod) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}
bool fermat_prime(long long n) {
    if (n < 7) return n == 2 || n == 3 || n == 5;
    for (int _ = 1; _ <= k; _++) {
        long long a = rand() % (n - 3) + 2; // a thuộc khoảng [2, n-1]
        if (expo(a, n-1, n) != 1) return 0;
    }
    return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int cnt = 0;
    int t; cin >> t; while (t--) {
        int a; cin >> a; cnt += fermat_prime(a);
    }
    cout << cnt;
}
