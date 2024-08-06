#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    string s, t; cin >> s >> t;
    int ns = s.size(), nt = t.size();
    s += ' ';
    int r = 0;
    for (int l = 0; l < nt; l++) {
        while (r < ns && s[r] != t[l] && s[r] != '?') r++;
        if (s[r] == t[l]) r++;
        else if (r == ns) {
            cout << "NO\n";
            return;
        }
        else if (s[r] == '?') {
            s[r] = t[l];
        }
        cout << l << ' ' << r << '\n';
    }
    if (r == ns) {
        cout << "YES\n";
        for (int i = 0; i < ns; i++) { if (s[i] == '?') cout << 'z'; else cout << s[i]; }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }
}
/*
aaaaa?a
axxa
YES
aaaaaxa
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}