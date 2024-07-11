// https://tleoj.edu.vn/problem/34c
#include <iostream>
#include <chrono>
#include <random>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;
#define u64 long long
#define u128 long long

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
u64 rd(u64 l, u64 r) { return uniform_int_distribution<u64>(l, r)(rng); }

u64 expo(u64 a, u64 b, u64 mod) {
    if (b == 0) return 1;
    u64 t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b & 1 ? a : 1) % mod;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = expo(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 11) return n == 2 || n == 3 || n == 5 || n == 7;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return 0;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = rd(2, n-1);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    u64 cnt = 0;
    u64 t; cin >> t; while (t--) {
        u64 a; cin >> a; cnt += MillerRabin(a);
    }
    cout << cnt;

}