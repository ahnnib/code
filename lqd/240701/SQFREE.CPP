#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("SQFREE.INP", "r", stdin);
    freopen("SQFREE.OUT", "w", stdout);

    ll n;
    while (cin >> n) {
        vector < pair <ll, int> > v;
        ll nn = n;
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) n /= i, cnt++;
                v.push_back(make_pair(i, cnt));
            }
        }
        for (int i = 0; i < v.size(); i++) {
            while (v[i].second >= 2) v[i].second--, nn /= v[i].first;
        }
        cout << nn << '\n';
    }
}
