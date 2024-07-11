#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define debug cout << "dfad\n";

void compress(vector<int> &v) {
    vector<int> dup = v;
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    for (int i = 1; i <= v.size(); i++) v[i] = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin() - 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("card.inp", "r", stdin);
    freopen("card.out", "w", stdout);
    #endif

    int n; cin >> n; vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector <int> b = v; // so phan tu nho hon v[i]
    compress(b);

    // for (auto i : b) cout << i << ' ';
    // cout << '\n';

    int t = abs(b[1] - 1 + 1);
    for (int i = 2; i <= b.size(); i++) {
        t = __gcd(t, abs(b[i] - i + 1));
    }

    vector<int> res;
    for (int k = 1; k <= t; k++) if (t % k == 0) res.push_back(k);
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}