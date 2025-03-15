#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("chess.inp", "r", stdin);
    freopen("chess.out", "w", stdout);
    int m, n; cin >> m >> n;

    if (m > n) swap(m, n);
    /*
    m < n
    k chan: (k / 2) * k = min(m, n) = m
    k le: k * k + 1 / 2, k * k + 1 / 2 - 1 = min(m, n) = m
    */
    if (m == n) { // m = n -> (m, n)
        cout << (int)sqrt(2 * m);
    }
    else { // m < n -> (m, m+1)
        cout << (int)sqrt(m + m + 1);
    }
}