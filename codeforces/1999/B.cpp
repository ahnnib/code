#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int res = 0;
    // a c, b d
    if ((a >= c && b > d) || (a > c && b >= d)) res += 2;
    // a d, b c
    if ((a > d && b >= c) || (a >= d && b > c)) res += 2;
    cout << res << '\n';
}
// 2 1 1 1 -> 2

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}