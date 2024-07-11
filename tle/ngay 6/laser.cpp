#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("laser.inp", "r", stdin);
    freopen("laser.out", "w", stdout);
    #endif

    long long l, w; cin >> l >> w;
    cout << l / w;
}