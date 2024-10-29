/*
ll dp[50][2];
ll f(int vt, int tt) {
    if (vt < 0) {
        return 1;
    }

    if (dp[vt][tt] != -1) {
        return dp[vt][tt];
    }

    ll res = 0;

    if (tt == 1) {
        res += f(vt - 1, 0);
    }
    if (tt == 0) {
        res += f(vt - 1, 0);
        res += f(vt - 1, 1);
    }


    return dp[vt][tt] = res;
}


int main() {
    int n; cin >> n;

    memset(dp, -1, sizeof dp);

    cout << f(n-1, 0);
}
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("dnp.inp", "r", stdin);
    freopen("dnp.out", "w", stdout);

    int n; cin >> n;

    int sz1 = n / 2, sz2 = n - sz1, digit;
    string s; vector<string> v1, v2;

    bool ok;
    for (int i = 0; i < (1<<sz1); i++) {
        ok = 1;
        for (int j = sz1-1; j >= 0; j--) {
            digit = i & (1<<j) ? '1' : '0';
            if (s[s.size()-1] + digit == 98) {
                ok = 0;
                break;
            }
            s.push_back(digit);
        }
        if (ok) v1.push_back(s);
        s = "";
    }
    if (sz1 != sz2) {
        for (int i = 0; i < (1<<sz2); i++) {
            ok = 1;
            for (int j = sz2-1; j >= 0; j--) {
                digit = i & (1<<j) ? '1' : '0';
                if (s[s.size()-1] + digit == 98) {
                    ok = 0;
                    break;
                }
                s.push_back(digit);
            }
            if (ok) v2.push_back(s);
            s = "";
        }
    }
    else v2 = v1;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int r = lower_bound(v2.begin(), v2.end(), "1", [](const std::string &a, const std::string &b) {
        return a < b;
    }) - v2.begin();

    ll res = 0;
    for (string t1 : v1) {
        if (t1[t1.size()-1] == '1') {
            res += r;
        }
        if (t1[t1.size()-1] == '0') {
            res += v2.size();
        }
    }
    cout << res;
}