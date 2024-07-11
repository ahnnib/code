#include <iostream>
#include <map>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    ll res = 0;
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        res += cnt[k - a[i]*a[i]];
    }
    cout << res;
}