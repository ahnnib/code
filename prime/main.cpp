#include <iostream>
#include <chrono>
#include <random>
using namespace std;
// using u128 = __int128_t;

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); long long rd(long long l, long long r) { return uniform_int_distribution<long long>(l, r)(rng); }

long long expo(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long t = expo(a, b>>1, mod) % mod;
    return t * t % mod * (b % 2 ? a : 1) % mod;
}
bool test(long long a, long long n, long long k, long long m) {

    long long mod = expo(a, m, n);
    if (mod == 1 || mod == n-1) return 1;

    for (int l = 1; l < k; l++) {
        mod = (mod * mod) % n;
        if (mod == n-1) return 1;
    }
    return 0;
}
bool rabin_miller_probabilistic(long long n) {
    if (n < 11) return n == 2 || n == 3 || n == 5 || n == 7;

    long long k = 0, m = n-1; while (m % 2 == 0) k++, m >>= 1;

    const static int rep = 1006209;
    for (int _ = 0; _ < rep; _++) {
        long long a = rd(2, n-1);
        if (!test(a, n, k, m)) return 0;
    }
    return 1;
}

void solve() {
    long long n; cin >> n;

    cout << (rabin_miller_probabilistic(n) ? "YES" : "NO");

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}