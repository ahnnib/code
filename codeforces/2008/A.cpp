#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int a, b; cin >> a >> b;
    if ((a == 0 && b%2) || (a%2 && b%2 == 0)) cout << "NO\n";
    else {
        cout << (a % 2 == 0 ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}