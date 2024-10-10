#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

int main() {
    ll n, x, y, a;
    cin >> n >> x >> y;

    map<ll, ll> mp1, mp2;
    map< pair <ll, ll> , ll > mp3;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;

        ll t1 = mp1[(x - (a % x))%x];
        ll t2 = mp2[a % y];
        ll t3 = mp3[{(x - (a % x))%x, a % y}];
        res += t1 + t2 - t3;

        mp1[a % x]++;
        mp2[a % y]++;
        mp3[{a % x, a % y}]++;
    }

    cout << res;
}