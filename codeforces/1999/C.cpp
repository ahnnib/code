#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n, s, m; cin >> n >> s >> m;
    int l[n], r[n];
    int rmax = 0, dist = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        dist = max(dist, l[i] - rmax);
        rmax = r[i];
    }
    dist = max(dist, m - rmax);
    if (dist >= s) cout << "YES";
    else cout << "NO";
    cout << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}