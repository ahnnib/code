#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    string s; cin >> s;

    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            char t = s[i] + 1 - (s[i] == 'z' ? 26 : 0);
            for (int j = 0; j < i; j++) cout << s[j];
            cout << t;
            for (int j = i; j < s.size(); j++) cout << s[j];
            cout << '\n';
            return;
        }
    }
    cout << char(s[0] + 1 - (s[0] == 'z' ? 26 : 0)) << s << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}
