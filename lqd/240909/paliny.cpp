#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 5e4 + 1;
int n; string s;

const ll mod = 98187917, bs = 521;
ll h1[N], h2[N], pw[N];
ll g1(int l, int r) {
    return (h1[r] - h1[l-1]*pw[r-l+1] % mod + mod*mod) % mod;
    
}
ll g2(int l, int r) { // reverse hash
    l = n-l+1; r = n-r+1; swap(l, r);
    return (h2[r] - h2[l-1]*pw[r-l+1] % mod + mod*mod) % mod;
}

int main() {
    freopen("paliny.inp", "r", stdin);
    freopen("paliny.out", "w", stdout);

    cin >> n >> s;

    s = ' ' + s;
    pw[0] = 1; for (int i = 1; i <= n; i++) pw[i] = pw[i-1] * bs % mod;
    for (int i = 1; i <= n; i++) {
        h1[i] = (h1[i-1] * bs + s[i]-'a'+1) % mod;
        h2[i] = (h2[i-1] * bs + s[n-i+1]-'a'+1) % mod;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = 1, r = min(i, n-i+1), mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            ll t1 = g1(i-mid+1, i), t2 = g2(i, i+mid-1);
            if (t1 == t2) l = mid + 1;
            else r = mid - 1;
        }
        res = max(res, r * 2 - 1);
    }
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i-1]) continue;
        int l = 1, r = min(n-i+1, i-1), mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            ll t1 = g1(i-mid, i-1), t2 = g2(i, i+mid-1);
            if (t1 == t2) l = mid + 1;
            else r = mid - 1;
        }
        res = max(res, r * 2);
    }
    cout << res;
}