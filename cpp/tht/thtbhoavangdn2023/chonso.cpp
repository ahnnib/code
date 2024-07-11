#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool ok(char ch) { return '0' <= ch && ch <= '9'; }
int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("choosstr.inp", "r", stdin);
    freopen("choosstr.out", "w", stdout);
    #endif

    string s; cin >> s;

    ll res = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        if (ok(s[i]) && ok(s[i+1]) && ok(s[i+2])) {
            ll t = (s[i] - 48) * 100 + (s[i+1] - 48) * 10 + (s[i+2] - 48);
            res = max(res, t);
        }
    }
    cout << res;
}

