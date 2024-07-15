#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, k, a[100000];
ll check(ll x) { // tao duoc bao nhieu thanh go do dai x
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a[i] / x;
    }
    return cnt;
}
int main() {
    freopen("part.inp", "r", stdin);
    freopen("part.out", "w", stdout);
    cin >> n >> k; for (int i = 0; i < n; i++) cin >> a[i];
    ll l = 1, r = 1e9, mid;   
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid) >= k) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
}