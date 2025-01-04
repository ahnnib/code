#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;

ll sol(string a, string b, string c) {

}

int main() {
    string a, b, c; cin >> a >> b >> c;

    ll res = sol(a, b, c);
    res = min(res, sol(a, c, b));
    res = min(res, sol(b, c, a));
    res = min(res, sol(b, a, c));
    res = min(res, sol(c, a, b));
    res = min(res, sol(c, b, a));

    cout << res;
}