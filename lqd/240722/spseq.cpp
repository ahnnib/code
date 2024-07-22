#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("spseq.inp", "r", stdin);
    freopen("spseq.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    int f[n], g[n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
        vector<int>::iterator t = lower_bound(v.begin(), v.end(), a[i]);
        if (t == v.end()) v.push_back(a[i]);
        else *t = a[i];
        f[i] = v.size();
    }
    // for (int i = 0; i < n; i++) cout << f[i] << ' ';
    v.clear();
    for (int i = n-1; i >= 0; i--) {
        vector<int>::iterator t = lower_bound(v.begin(), v.end(), a[i]);
        if (t == v.end()) v.push_back(a[i]);
        else *t = a[i];
        g[i] = v.size();
    }
    // for (int i = 0; i < n; i++) cout << g[i] << ' ';
    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, 2 * min(f[i], g[i]) - 1);
    cout << res;

}