#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, a[5000], cnt[2000005];
int main() {
    freopen("bai3.inp", "r", stdin);
    freopen("bai3.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[a[i]];
        for (int j = 0; j < i; j++) {
            cnt[a[i] + a[j]]++;
        }
    }
    cout << res;
}