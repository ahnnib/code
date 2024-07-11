#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define int long long

const int mod = 1e9 + 7;

int f(int x)
{
    int res = 1;
    while (x && res != 0)
    {
        res = ((res % mod) * (x % 10)) % mod;
        x /= 10;
    }
    return res;
}

signed main()
{
    freopen("smarter.inp", "r", stdin);
    freopen("smarter.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        ans = (ans % mod + f(i) % mod) % mod;
        // cout << f(i) << '\n';
    }

    cout << ans;
    // cout << f(25);
}