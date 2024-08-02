#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
const ll mod = 1e9 + 7;
int main() {
    freopen("del1.inp", "r", stdin);
    freopen("del1.out", "w", stdout);
    int n; cin >> n; ll a[n]; for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int cnt_am = 0, cnt_0 = 0;
    int l = 1; while (a[l] < 0) l++;
    cnt_am += l - 1;
    while (a[l] == 0) l++;
    cnt_0 += l - 1 - cnt_am;
    bool xoa_am = (cnt_am & 1) & (cnt_0 == 0);
    bool xoa_0 = !(cnt_am & 1) & (cnt_0 == 1);
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        if (xoa_am && i == cnt_am) continue;
        else if (xoa_0 && i == cnt_am + cnt_0) continue;
        res = (res * a[i]) % mod;
    }
    cout << res;
}
