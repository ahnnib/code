#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 5e6;
struct Seg {
    ll t[400007];
    ll get(int id, int l, int r, int l1, int r1) {
        if (l1 > r || r1 < l) {
            return 0;
        }
        if (l1 <= l && r <= r1) return t[id];
        int mid = (l + r) >> 1;
        return (get(2*id, l, mid, l1, r1) + get(2*id+1, mid+1, r, l1, r1)) % mod;
    }
    void update(int id, int l, int r, int pos, ll val) {
        if (pos < l || pos > r) return;
        if (l == r) {
            t[id] = val % mod;
            return;
        }
        int mid = (l + r) >> 1;
        update(2*id, l, mid, pos, val);
        update(2*id+1, mid+1, r, pos, val);
        t[id] = t[2*id] % mod + (t[2*id+1] % mod);
        t[id] %= mod;
    }
} seg[51];

void compress(vector<int> &v) {
    vector<int> dup = v;
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    for (int &i : v) {
        i = lower_bound(dup.begin(), dup.end(), i) - dup.begin();
    }
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    compress(a);

    for (int i = 0; i < n; i++) {
        seg[1].update(1, 0, n-1, a[i], seg[1].get(1, 0, n-1, a[i], a[i]) + 1);
        for (int len = 2; len <= k; len++) {
            ll t = seg[len-1].get(1, 0, n-1, 0, a[i]-1) % mod;
            ll old = seg[len].get(1, 0, n-1, a[i], a[i]);
            seg[len].update(1, 0, n-1, a[i], (old + t) % mod);
        }
    }

    cout << seg[k].get(1, 0, n-1, 0, n-1);
}