#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; string s; cin >> n >> s;
    if (sqrt(n) == int(sqrt(n))) {
        int t = sqrt(n), cnt1 = 0, cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cnt1++;
            else cnt0++;
        }
        if (4 * (t - 1) == cnt1 && (t - 2) * (t - 2) == cnt0) cout << "YES\n";
        else cout << "NO\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}