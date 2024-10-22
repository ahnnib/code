#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    // freopen("dnp.inp", "r", stdin);
    // freopen("dnp.out", "w", stdout);

    int n; cin >> n;

    int sz1 = n / 2, sz2 = n - sz1, digit;
    string s; vector<string> v1, v2;

    for (int i = 0; i < (1<<sz1); i++) {

        for (int j = sz1-1; j >= 0; j--) {

            digit = i & (1<<j) ? 1 : 0;
            if (s[s.size()-1] + digit == 96) break;

            s.push_back(digit);
        }

        v1.push_back(s);
        s = "";
    }

    if (sz1 != sz2) {
        for (int i = 0; i < (1<<sz2); i++) {

            for (int j = sz2-1; j >= 0; j--) {

                digit = i & (1<<j) ? 1 : 0;
                if (s[s.size()-1] + digit == 96) break;

                s.push_back(digit);
            }

            v2.push_back(s);
            s = "";
        }
    }
    else v2 = v1;

    ll cnt = 0;
    for (string t1 : v1) for (string t2 : v2) {
        cout << t1 << ' ' << t2 << '\n';
        if (t1[t1.size()-1] + t2[0] == 96) cnt++;
    }

    cout << cnt;
}