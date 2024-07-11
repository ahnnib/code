// dãy con tăng có tổng lớn nhất
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int n; vector<int> a;

vector<int> s;

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) { s[id] = val; return; }
    int mid = (l + r) >> 1;
    update(2*id, l, mid, pos, val); update(2*id+1, mid+1, r, pos, val);
    s[id] = max(s[2*id], s[2*id+1]);
}
int get(int id, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return s[id];
    int mid = (l + r) >> 1;
    return max(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
}
void _update(int pos, int val) { update(1, 1, n, pos, val); }
int _get(int l, int r) { return get(1, 1, n, l, r); }

void compress(vector<int> &v) {
    vector<int> dup = v;
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    for (int i = 0; i < v.size(); i++) {
        v[i] = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin() + 1;
    }
}

signed main()
{
    cin >> n; a.resize(n+1); s.resize(4 * n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> comp = a;
    compress(comp);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = _get(1, comp[i] - 1);
        _update(comp[i], res + a[i]);
        ans = max(ans, res + a[i]);
    }
    // for (int i = 0; i <= 4 * n; i++) cout << s[i] << ' ';

    cout << ans;
}
