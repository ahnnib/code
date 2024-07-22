#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        vector<int>::iterator t = lower_bound(dp.begin(), dp.end(), a[i]);
        if (t == dp.end()) dp.push_back(a[i]);
        else *t = a[i];
    }
    cout << dp.size();
}