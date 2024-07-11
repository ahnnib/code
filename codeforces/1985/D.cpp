#include <iostream>
#include <algorithm>
using namespace std;

bool mxm(int &x, int y) { return x < y ? x = y, 1 : 0; }
void solve() {
    int n, m; cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        cin >> g[i][j];
        }
    }
    int h1, h2, k;
    for (int i = 0; i < n; i++) {
        if (count(g[i], g[i] + m, '#') == 1) { h1 = i; break; }
    }
    for (int i = n-1; i >= 0; i--) {
        if (count(g[i], g[i] + m, '#') == 1) { h2 = i; break; }
    }
    for(int j = 0; j < m; j++) if (g[h1][j] == '#') { k = j; break; }

    cout << (h2 + h1) / 2 + 1<< ' ' << k + 1 << '\n';

}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}