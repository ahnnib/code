#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define ll long long

ll phi(ll n) {
    ll cnt = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt += 2;
            if (i == n / i) cnt--;
        }
    }
    return n - cnt;
}
signed main()
{
    ll x, y, m; cin >> x >> y >> m;
    for (int i = 1; i <= 1; i++) {
        x = phi(x) + y;
    }
    cout << x;
}
