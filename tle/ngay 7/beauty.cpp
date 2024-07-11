#include <iostream>
using namespace std;

const int mod = 24022007;

bool beauty(int n) {
    while (n) {
        if (n % 10 != 6 && n % 10 != 9) return false;
        n /= 10;
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("beauty.inp", "r", stdin);
    freopen("beauty.out", "w", stdout);
    #endif

    int cnt = 0;
    int n; cin >> n;
    if (!beauty(n)) return cout << -1, 0;
    for (int i = n-1; i > 2; i--) {
        cnt += beauty(i);
    }
    cout << cnt % mod;
}