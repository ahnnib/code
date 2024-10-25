#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;

    int a[n];
    vector< pair<int, int> > dp;
    vector<int> parent(n, -1);
    vector<int> res;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), make_pair(a[i], i), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        });
        if (it > dp.begin()) {
            parent[i] = (it - 1)->second;
        }
        if (it == dp.end()) dp.push_back({a[i], i});
        else *it = {a[i], i};
    }

    for (int i = dp.back().second; i >= 0; i = parent[i]) {
        res.push_back(i);
    }

    reverse(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto i : res) cout << i + 1 << ' ';
}