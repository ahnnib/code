#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("uocnt.inp", "r", stdin);
    freopen("uocnt.out", "w", stdout);

    ll n; cin >> n;

    vector < int > v;
    for (int i = 2; (ll)i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            v.push_back(i);
        }
    }

    cout << v.size() + (n > 1) << '\n';
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    if (n > 1) cout << n;
}
