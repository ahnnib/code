#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int t; cin >> t; while (t--) {
        long long n, m, a, b;
        cin >> n >> m;

        long long t1 = 1, t2 = 1;
        for (int i = 0; i < n; i++)
            cin >> a,
            (t1 *= (a % mod)) %= mod;
        for (int i = 0; i < m; i++)
            cin >> b,
            (t2 *= (b % mod)) %= mod;

        cout << (t1 == t2 ? "YES\n" : "NO\n");
    }
}