#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

#define d first
#define w second

const int N = 1e5 + 1;
int n, m;
pair<ll, ll> a[N]; ll sum_w[N], sum_dw[N];

int main() {
    freopen("talent.inp", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i].d;
    for (int i = 1; i <= n; i++) cin >> a[i].w;

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++) {
        sum_w[i] = sum_w[i-1] + a[i].w;
        sum_dw[i] = sum_dw[i-1] + a[i].w * a[i].d;
    }

    int l, r, mid; ll p;
    while (m--) {
        cin >> p;
        l = 1, r = n, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[mid].d < p) l = mid + 1;
            else r = mid - 1;
        }
        // p <= d[i] -> l -> n
        ll g1 = sum_dw[n] - sum_dw[l-1] - p * (sum_w[n] - sum_w[l-1]);
        // p > d[i] -> 1 -> r
        ll g2 = p * sum_w[r] - sum_dw[r];
        cout << g1 + g2 << '\n';
    }
}