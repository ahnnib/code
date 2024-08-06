#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; cin >> n; int res = 0; while (n) res += n % 10, n /= 10; cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}