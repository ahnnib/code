#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    string s, t; cin >> s >> t;
    int ns = s.size(), nt = t.size();
    int j = 0;
    for (int i = 0; i < ns; i++) {
        if (s[i] == '?') {
            if (j < nt) s[i] = t[j++];
            else s[i] = 'z';
        }
        else if (s[i] == t[j]) j++;
    }
    if (j < nt) cout << "NO";
    else cout << "YES" << '\n' << s;
    cout << '\n';
}
/*
aaaaa?a
axxa
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}