#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

string s; int k, x, nd;

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);
    #endif

    cin >> s >> x;
    nd = s.size();
    int xx = x; while (xx > 0) xx /= 10, k++; xx = x;
    int X[k]; for (int i = k-1; i >= 0; i--) {
        X[i] = xx % 10;
        xx /= 10;

    }
//    for (int i = 0; i < nd; i++) {
//        cout << X[i % k] << ' ';
//    }
    for (int i = 0; i < nd; i++) {
        char ch = s[i] + X[i % k];
        if (ch > 'Z') ch -= ('Z' - 'A' + 1);
        cout << ch;
    }
}
/*
0 1 2 3 0 1 2 3 0 1 2 3
3 2 1 0 3 2 1 0
*/

