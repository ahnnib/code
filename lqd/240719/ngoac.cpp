#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("ngoac.inp", "r", stdin);
    freopen("ngoac.out", "w", stdout);
    int n; cin >> n;

    vector<string> res;
    for (int i = 0; i < (1<<n); i++) {
        string t;
        for (int j = n-1; j >= 0; j--) {
            t += i & (1<<j) ? '(' : ')';
        }
        int c = 0; bool ok = 1;\
        for (char k : t) {
            if (k == '(') c++;
            if (k == ')') {
                if (c > 0) c--;
                else { ok = 0; break; }
            }
        }
        if (c != 0) ok = 0;
        if (ok) res.push_back(t);
    }
    sort(res.begin(), res.end());
    for (string i : res) cout << i << '\n';
    cout << res.size();

}