#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";
/*
bool prime(ll n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}
ll calc(ll n) {
    vector<int> d; for (int i = 1; i <= n; i++) d.push_back(i);

    ll res = 0;
    do {
        bool ok = true;
        for (int i = 1; i <= n && ok; i++) {
            ok &= prime(i + d[i - 1]);
        }
        res += ok;
    } while (next_permutation(d.begin(), d.end()));

    ll fact = 1; for (ll i = 1; i <= n; i++) fact = fact * i;
    res = res * fact / 2;
    return res;
}
*/

ll n;
int ans[8] = {0, 1, 3, 48, 60, 3240, 10080, 725760};
void sol() {
    cin >> n;
    cout << ans[n-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}