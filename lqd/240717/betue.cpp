#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll n, m, a[300000];

ll kt(ll x) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        
    }
    return res;
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    ll l = 1, r = 1e9, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (kt(mid) < m) r = mid - 1;
        else l = mid + 1;
    }
    cout << r;
}