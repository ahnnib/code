#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n; cin >> n;
    int d[10] = {1, 4, 7, 0, 3, 6, 9, 2, 5, 8};
    int t = 45;
    ll res = 1ll * (n / 10) * t;
    n %= 10;
    for (int i = 0; i < n; i++) {
        res += d[i];
    }
    cout << res;
}

