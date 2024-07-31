#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; cin >> n;
    bool g[2][n];
    for (int i : {0, 1}) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            g[i][j] = (c == '.' ? 1 : 0);
        }
    }
    int cnt = 0;
    for (int i = 1; i < n-1; i++) {
        if (g[0][i-1] && g[0][i] && g[0][i+1] && g[1][i] && !g[1][i-1] && !g[1][i+1]) {
            cnt++;
        }
        if (g[1][i-1] && g[1][i] && g[1][i+1] && g[0][i] && !g[0][i-1] && !g[0][i+1]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}