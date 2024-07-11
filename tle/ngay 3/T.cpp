#include <iostream>
using namespace std;

#define int long long

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("t.inp", "r", stdin);
    freopen("t.out", "w", stdout);
    #endif

    int n; cin >> n; while (n--) {
        int T, S; cin >> T >> S;
        int t; for (int i = 0; i < S; i++) {
            cin >> t;
            cout << (t <= T ? "AC" : "TLE") << ' ';
        }
        cout << '\n';
    }
}