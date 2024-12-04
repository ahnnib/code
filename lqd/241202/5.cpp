#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;

    vector<pair<ll, ll>> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<ll, ll>& x, pair<ll, ll>& y) {
        return abs(x.first - x.second) > abs(y.first - y.second);
    });

    ll res = 0, cntA = 0, cntB = 0;

    for (int i = 0; i < 2 * n; i++) {
        if ((a[i].first <= a[i].second && cntA < n) || cntB == n) {
            res += a[i].second;
            cntA++;
        }
        else {
            res += a[i].first;
            cntB++;
        }
    }

    cout << res;
}