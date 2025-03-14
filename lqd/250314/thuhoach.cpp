#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";
#define c second
#define x first

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("thuhoach.inp", "r", stdin);
    freopen("thuhoach.out", "w", stdout);
    int n, k; cin >> n >> k;
    pair<ll, ll> a[n+1] = {};
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c >> a[i].x;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        a[i].c += a[i-1].c;
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[mid].x > a[i].x + 2*k) r = mid - 1;
            else l = mid + 1;
        }
        res = max(res, a[r].c - a[i-1].c);
    }
    cout << res;
}