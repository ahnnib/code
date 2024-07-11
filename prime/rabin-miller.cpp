// https://tleoj.edu.vn/problem/34c
#include <bits/stdc++.h>
using namespace std;
#define ll long long
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rand(ll l=0,ll r=1e18)
{
    return uniform_int_distribution<long long>(l, r)(rng);
}
long long expo(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b % 2 ? a : 1) % mod;
}
bool test(long long a, long long k, long long n, long long m) {
    // a^m
    long long mod = expo(a, m, n);
    if (mod == 1 || mod == n-1) return 1;
    // a^(2^l * m)
    for (int l = 1; l < k; l++) {
        mod = ((mod%n) * (mod%n)) % n;
        if (mod == n-1) return 1;
    }
    return 0;
}
const int rep = 5;
bool rabin_miller_probabilistic(long long n) {
    // small cases
    if (n < 11) return n == 2 || n == 3 || n == 5 || n == 7;
    // n-1 = 2^k * m
    long long k = 0, m = n-1; while (m % 2 == 0) m >>= 1, k++;
    // test
    for (int _ = 0; _ < rep; _++) {
        long long a =  rand(2,n-1) ;
        if (!test(a, k, n, m)) return 0;
    }
    return 1;
}
bool rabin_miller_deterministic(long long n) {
    // small cases
    if (n < 11) return n == 2 || n == 3 || n == 5 || n == 7;
    // 2^k * m
    long long k = 0, m = n-1; while (m % 2 == 0) m /= 2, k++;
    // test
    // n <= 3e9: 2, 3, 5, 7
    // n <= LONG_LONG_MAX + 1: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
    vector<ll>check = {2, 3, 5, 7};
    for (long long a : check) {
        if (!test(a, n, k, m)) return 0;
    }
    return 1;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    // int cnt = 0;
    // int n; cin >> n; while (n--) {
    //     long long a; cin >> a; cnt += rabin_miller_probabilistic(a);
    // }
    // cout << cnt;
    int t; cin >> t; while (t--) {
        int a; cin >> a; cout << rabin_miller_deterministic(a);
    }
}