#include <iostream>
using namespace std;

// limit
const int N = 1e5;
const long long BASE = 311;
const long long MOD = 1e9 + 7;

// memory
long long h[N + 5];
long long power[N + 5]; // power[i] = BASE^i;

long long geth(int l, int r) // \sum_{i=1}^{\left|S\right|-1}s\left[i\right]\cdot\left(BASE\right)^{i}
{
    return ((h[r] - (h[l-1] * power[r - l + 1]) % MOD + MOD) % MOD);
}

int main()
{

    string s;
    cin >> s;
    int n = (int) s.size();

    // precalc
    power[0] = 1;
    for (int i = 1; i <= n; i++) power[i] = power[i-1] * BASE % MOD;

    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = (h[i-1] * BASE + s[i-1] - 'a' + 1) % MOD;

    cout << geth(0, n-1); // test hash
}

// dfad