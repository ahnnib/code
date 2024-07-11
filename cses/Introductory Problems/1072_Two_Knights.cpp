#include <iostream>
using namespace std;

int main()
{
    /*
    inclusion - exclusion
    number of ways to place two knights on the board: k^2 * (k^2-1) / 2
    the number of distinct ways to place two knights so that they attack each other:
    8 * (k-1) * (k-2) / 2
    */
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++)
        cout << 1ll * k*k * (k*k-1) / 2 - 1ll * 4 * (k-1) * (k-2) << '\n';
}
