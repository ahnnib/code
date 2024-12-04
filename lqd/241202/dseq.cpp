#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    ll s[n+1] = {}, a[n+1] = {};

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    ll res = -1e18;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            res = max(res, abs(s[i] - (s[n] - s[j-1])));
        }
    }

    cout << res;
}