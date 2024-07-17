#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("clan.inp", "r", stdin);
    freopen("clan.out", "w", stdout);
    map<ll, ll> cnt;
    int n; cin >> n; while (n--) {
        ll a; cin >> a; cnt[a]++;
    }
    ll res = 0;
    for (auto &[i, j] : cnt) res += j / i;
    cout << res;
}