#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 2e6 + 1;
ll n, a[N], cnt[N], s[N];

int main() {
    freopen("tgcan.inp", "r", stdin);
    freopen("tgcan.out", "w", stdout);
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        cnt[a[i]]++;
    }

    sort(a + 1, a + 1 + n);

    for (int i = 1; i < N; i++) {
        s[i] = s[i-1] + cnt[i];
    }

    ll res = 0;
    for (ll i = 1; i <= mx; i++) {
        // so tg can
        ll sl = s[min(2 * i - 1, mx)] - cnt[i];
        res += (cnt[i] * (cnt[i] - 1) / 2) * sl;
        // so tg deu
        res += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
    }
    cout << res;
}