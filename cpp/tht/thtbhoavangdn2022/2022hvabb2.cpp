#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("addsubtract.inp", "r", stdin);
    freopen("addsubtract.out", "w", stdout);

    string s; cin >> s;
    ll res = 0;
    int op;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') op = 1;
        else if (s[i] == '-') op = -1;
        else {
            ll num = 0;
            while ('0' <= s[i] && s[i] <= '9') {
                num = num * 10 + s[i] - 48;
                i++;
            } i--;
            res = res + op * num;
        }
    }
    cout << res;
}
