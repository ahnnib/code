#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("tongchuso.inp", "r", stdin);
    freopen("tongchuso.out", "w", stdout);
    #endif

    string n; cin >> n;
    ll res = 0;
    for (int i = 0; i < n.size(); i++) {
        res += n[i] - 48;
    }
    cout << res;
}