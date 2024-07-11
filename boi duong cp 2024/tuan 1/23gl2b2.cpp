// https://lqdoj.edu.vn/problem/23gl2b2
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    long long s = a[0], res = 0;
    for (int j = 1; j < n; j++) {
        res = (res + (1ll * a[j] * s) % MOD) % MOD;
        s = (s + a[j]) % MOD;
    }

    cout << res;
}