#include <iostream>
using namespace std;

void solve() {
    string a, b; cin >> a >> b;
    char t = a[0];
    a[0] = b[0];
    b[0] = t;
    cout << a << ' ' << b << "\n";
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}