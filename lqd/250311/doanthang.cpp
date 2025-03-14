#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cin.tie(0);
#define MAX 1000005

ll tree [4 * MAX]{0};
ll i, j, n, x, y, a[100005];
vector <pair <ll, ll> > vt;

bool cmp (pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

void update (ll id, ll l, ll r, ll pos, ll val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        tree [id] = val;
        return;
    }
    ll m = (l + r) / 2;
    update (id * 2, l, m, pos, val);
    update (id * 2 + 1, m + 1, r, pos, val);
    tree[id] = max (tree [id * 2], tree [id * 2 + 1]);
}

ll get (ll id, ll l, ll r, ll a, ll b) {
    if (b < l || r < a) return 0;
    if (a <= l &&  r <= b) return tree [id];
    ll m = (l + r) / 2;
    return max (get (id * 2, l, m, a, b), get (id * 2 + 1, m + 1, r, a, b));
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
	for (i = vt.size() - 1; i >= 0; i--) {
//		cout << vt[i].first << " " << vt[i].second << endl;
		ll so = get (1, 1, MAX, 0, vt[i].second);
		ll so2 = get (1, 1, MAX, vt[i].second, vt[i].second);
		update (1, 1, MAX, vt[i].second, max (so2, so + 1));
	}
	cout << get (1, 1, MAX, 0, MAX);
}
/*
bool cmp (pair<int, int>a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main () {
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> x >> y;
		vt.push_back ({x, y});
	}
	sort (vt.begin(), vt.end(), cmp);
    vector<int> dp;
	for (i = vt.size() - 1; i >= 0; i--) {
        auto it = upper_bound(dp.begin(), dp.end(), vt[i].second); // upper_bound accounts for segments with overlapping endpoint while lower_bound only allows segments with strictly less-than endpoint
        if (it == dp.end()) dp.push_back(vt[i].second);
        else *it = vt[i].second;
	}
    cout << dp.size();
}
*/