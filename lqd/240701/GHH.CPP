#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // freopen("GHH.INP", "r", stdin);
    // freopen("GHH.OUT", "w", stdout);

    vector<int> res;
    int n; cin >> n;
    while (n--) {
        // a <= k
        int a; cin >> a;
        ll k = 1;
        for (int i = 2; i * i <= a; i++) {
            if (a % i == 0) {
                k += i + (i != a/i ? a/i : 0);
            }
        }
        if (a <= k) res.push_back(a);
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) cout << res[i] << '\n';
}
