// https://lqdoj.edu.vn/problem/gcdset
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve() {
    int n; long long k; cin >> n >> k; long long a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    long long res = a[0];
    for (long long i : a) {
        if (i % k == 0) res = gcd(res, i / k);
    }

    cout << (res == 1 ? "YES\n" : "NO\n");
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}