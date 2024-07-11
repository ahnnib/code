#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    string s; cin >> s;

    string r = s; reverse(r.begin(), r.end());
    for (int i = 1; i < s.size(); i++) {
        if (s[i] - s[i-1] != r[i] - r[i-1]) { cout << "NO\n"; return; }
    }
    cout << "YES\n";

}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("happystr.inp", "r", stdin);
    freopen("happystr.out", "w", stdout);
    #endif

    int n; cin >> n; while (n--) {
        solve();
    }
}