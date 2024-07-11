#include <iostream>
using namespace std;

int main()
{
    int q; cin >> q; while (q--) {
        int n; cin >> n;
        long long t = n - (n % 2);
        cout << (t + 1) * (t >> 1) - (n % 2 ? 1ll*n*n : 0) << '\n';
    }
}
/*
3 7 11 15
*/
