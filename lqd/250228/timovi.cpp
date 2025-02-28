#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, k, m;
int main() {
    freopen("timovi.inp", "r", stdin);
    freopen("timovi.out", "w", stdout);
    cin >> n >> k >> m;

    ll len = 2 * n - 2;
    ll sl = m / k;
    ll cyc = sl / len;

    int a[2*n+1] = {};
    for (int i = 1; i <= 2 * n - 2; i++) {
        a[i] += cyc * k;
        m -= cyc * k;
    }

    int i = 1;
    while (m >= k) {
        a[i++] += k;
        m -= k;
    }
    a[i] += m;

    for (int i = 1; i < n; i++) {
        cout << a[i] + a[2 * n - i] << ' ';
    }
    cout << a[n];
}