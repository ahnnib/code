#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void sol() {
    ll n, k; cin >> n >> k;
    ll sum = n * k + n * (n - 1) / 2;
    ll l = 0, r = n-1, mid;
    auto cal = [&sum, &k](ll i) -> ll {
        return (i + 1) * k + i * (i + 1) / 2;
    };
    while (l <= r) {
        mid = (l + r) >> 1;
        ll t = cal(mid);
        if (t <= sum - t) l = mid + 1;
        else r = mid - 1;
    }
    ll t1 = cal(r), t2 = cal(l);
    cout << min(abs(t1 - (sum - t1)), abs(t2 - (sum - t2))) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}