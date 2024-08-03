#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; cin >> n; string s; cin >> s;
    int cnt = 0;
    for (string t : {"mapie", "map", "pie"}) {
        int len = t.size();
        for (int i = 0; i + len - 1 < s.size(); i++) {
            if (s.substr(i, len) == t) {
                s[(i + i+len-1) / 2] = '?'; // replace middle character
                cnt++;
            }
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