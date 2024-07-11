#include <iostream>
using namespace std;

#define int long long
#define debug cout << "dafd\n";
#define FOR(i, l, r) for (int i = l; i <= r; i++)

void sub1(int &n, int &m) {
    cout << n * (n + 1) / 2 * m * (m + 1) / 2;
}
void sub2a() {}
void sub2b() {}


signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("o.inp", "r", stdin);
    freopen("o.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    char a[n][m];
    bool s1 = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '1') s1 = false;
    }

    if (s1) sub1(n, m);
    // if (n == 1) sub2a();
    // if (m == 1) sub2b();

    bool c;
    int res = 0;
    FOR (i, 0, n-1) {
        FOR (j, 0, m-1) {
            FOR (u, i, n-1) {
                FOR (v, j, m-1) {
                    c = 1;
                    FOR (x, i, u) if (a[x][j] == '1' || a[x][v] == '1') { c = 0; break; }
                    FOR (x, j, v && c) if (a[i][x] == '1' || a[u][x] == '1') {c = 0; break; }
                    if (c) {
                        res++;
                        // cout << i << ' ' << j << ' ' << u << ' ' << v << "\n";
                    }
                }
            }
        }
    }
    cout << res;
}
/*

*/