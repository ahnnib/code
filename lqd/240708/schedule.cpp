#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

struct Xe { ll a, b; };

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("schedule.inp", "r", stdin);
    freopen("schedule.out", "w", stdout);
    #endif

    int n; cin >> n;
    Xe xe[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) cin >> xe[i].a, sum += xe[i].a;
    for (int i = 0; i < n; i++) cin >> xe[i].b;

    sort(xe, xe + n, [](Xe &k, Xe &u) -> bool {
        return k.b * u.a < k.a * u.b;
    });

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += sum * xe[i].b;
        sum -= xe[i].a;
    }
    cout << res;
}