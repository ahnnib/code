#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n, k; cin >> n >> k;
    if (n % (k+1) != 0) cout << "Tho Win\n";
    else cout << "Rua Win\n";

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}