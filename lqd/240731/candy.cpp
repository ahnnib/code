#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n-1, res = 0;
    while (l < r) res += a[r--] - a[l++];
    for (int i = 0; i < n; i++) res += a[i];
    cout << res;
}