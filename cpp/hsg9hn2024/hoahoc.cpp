#include <iostream>
using namespace std;

#define ld long double

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("hoahoc.inp", "r", stdin);
    freopen("hoahoc.out", "w", stdout);
    #endif

    long long a, b; cin >> a >> b;

    long long t1 = a / 3, t2 = b / 2;

    // cout << t1 << '\n' << t2 << '\n';

    if (t1 > t2) cout << b / 2; // Fe dư, tính theo O2
    else if (t1 < t2) cout << a / 3; // O2 dư, tính theo Fe
    else cout << b / 2;

}
/*
104764536925032682 38352825235498720
=> t1 < t2

theo pt: 3/2t2, t2, 1/2t2
*/