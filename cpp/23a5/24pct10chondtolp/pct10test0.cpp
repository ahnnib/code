#include <iostream>
using namespace std;

#define ll long long

ll tcs(ll x)
{
    ll res = 0;
    while (x) res += x % 10, x /= 10;
    return res;
}

int main()
{
    // for (ll i = 0; i <= 1000; i++)
    // {
    //     if (!(tcs(i) % 2)) cout << i << ' ';
    // }
    // cout << '\n';
    // for (ll n = 0; n <= 1000; n++)
    // {
    ll n;
    cin >> n;


    if (n == 1) cout << 0;
    else {
    ll t1 = (n - 1) / 5;
    ll t2 = n % 5;
    if (t2 == 0) t2 = 5;
    if (t1 != 0) cout << t1;
    if (tcs(t1) % 2 == 0)
    {
        cout << 0 + 2 * (t2 - 1);
    }
    else if (tcs(t1) % 2 == 1)
    {
        cout << 1 + 2 * (t2 - 1);
    }
    }
    // cout << ' ';
    // }
}
/*

*/