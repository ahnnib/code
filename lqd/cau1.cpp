#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, a[300000]; map<int, int> b, cnt;
int main() {
    freopen("cau1.inp", "r", stdin);
    freopen("cau1.out", "w", stdout);
    cin >> n;
    int g = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] /= g;
        b[a[i]]++;
    }
    int res = n;
    for (int uoc = 1; uoc <= mx; uoc++) {
        for (int j = uoc; j <= mx; j += uoc) {
            cnt[uoc] += b[j];
        }
        if (uoc != 1) res = min(res, n - cnt[uoc]);
    }
    if (res == n) cout << -1;
    else cout << res;
}
