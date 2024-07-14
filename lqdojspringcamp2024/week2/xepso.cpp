#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("maxnum.inp", "r", stdin);
    freopen("maxnum.out", "w", stdout);
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, [](int a, int b) {
        ll t1 = a * pow(10, (int)log10(b)+1) + b;
        ll t2 = b * pow(10, (int)log10(a)+1) + a;
        return t1 > t2;//return t1>=t2;
    });
    for (int i = 0; i < n; i++) cout << a[i];
}
