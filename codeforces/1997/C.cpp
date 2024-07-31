#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void solve() {
    int n; string s; cin >> n >> s;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') c++;
        else if (s[i] == ')') c--;
        else {
            if (c > 0) s[i] = ')', c--;
            else s[i] = '(', c++;
        }
    }
    int res = 0; for (int i = 0; i < n; i++) {
        res += (s[i] == '(' ? -i : i);
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}