#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("tile.inp", "r", stdin);
    freopen("tile.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= h) h++;
    }
    cout << h;
}