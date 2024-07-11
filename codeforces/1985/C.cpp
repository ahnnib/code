#include <iostream>
using namespace std;

#define ll long long

void solve() {
    int n; cin >> n;
    ll sum = 0; int mx = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        mx = max(mx, a);
        if (sum - mx == mx) cnt++;
    }
    cout << cnt << '\n';
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}