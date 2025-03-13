#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cin.tie(0);
#define MAX 1000005

ll i, j, n, x, y, a[100005];
vector <pair <ll, ll> > vt;

bool cmp (pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main () {
	freopen ("DOANTHANG.INP", "r", stdin);
	freopen ("DOANTHANG.OUT", "w", stdout);
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		vt.push_back ({x, y});
	}
	sort (vt.begin(), vt.end(), cmp);
    vector<int> dp;
	for (i = vt.size() - 1; i >= 0; i--) {
        auto it = lower_bound(dp.begin(), dp.end(), vt[i].second);
        if (it == dp.end()) dp.push_back(vt[i].second);
        else *it = vt[i].second;
	}
    cout << dp.size();
}