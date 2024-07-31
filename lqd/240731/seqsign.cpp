#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
ll n, k, a[100005];
const ll mod = 1e9 + 7;
void sub1() {
    ll res = 0;
    for (int i = 0; i < (1<<n); i++) {
        ll sum = 0;
        for (int j = n-1; j >= 0; j--) {
            if (i & (1<<j)) sum += a[j];
            else sum -= a[j];
        }
        if (sum % k == 0) {
            res++;
            if (res > mod) res %= mod;
        }
    }
    cout << res;
}
int main() {
    freopen("seqsign.inp", "r", stdin);
    freopen("seqsign.out", "w", stdout);
    cin >> n >> k; for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 20) sub1();
}