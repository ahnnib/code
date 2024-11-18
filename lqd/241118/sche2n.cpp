#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("sche2n.inp", "r", stdin);
    freopen("sche2n.out", "w", stdout);
    int n; cin >> n;

    vector<pair<int, int>> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y) {
        return abs(x.first - x.second) > abs(y.first - y.second);
    });

    int res = 0, cntA = 0, cntB = 0;

    for (int i = 0; i < 2 * n; i++) {
        if ((a[i].first <= a[i].second && cntA < n) || cntB == n) {
            res += a[i].first;
            cntA++;
        }
        else {
            res += a[i].second;
            cntB++;
        }
    }

    cout << res;

}