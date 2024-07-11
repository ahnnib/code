#include <iostream>
using namespace std;

int main()
{
    int n, q; cin >> n >> q;
    int a[n+1] = {}; for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] ^= a[i-1];
    }
    while (q--) {
        int x, y; cin >> x >> y;
        cout << (a[y] ^ a[x-1]) << '\n';
        // proof: https://usaco.guide/problems/cses-1650-range-xor-queries/solution
    }
}