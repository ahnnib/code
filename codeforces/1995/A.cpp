#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n, k; cin >> n >> k;
    if (k == 0) { cout << "0\n"; return; }
    int sum = n, cnt = 1; n -= 1;
    while (sum < k) {
        sum += n; cnt++;
        if (sum >= k) break;
        sum += n; cnt++; n--;
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}