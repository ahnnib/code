#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define int long long

const int mod = 1e9 + 7;

signed main()
{
    freopen("noname.inp", "r", stdin);
    freopen("noname.out", "w", stdout);

    string s;
    int l;
    cin >> s >> l;
    int d[123] = {};

    int x = l / s.size();
    int y = l % s.size();
    // if (y > 0) x++;
    // cout << x << ' ' << y << '\n';
    for (int i = 0; i < s.size(); i++)
    {
        if (i < y)
            d[s[i]] = ((d[s[i]] % mod) + ((x+1) % mod)) % mod;
        else
            d[s[i]] = ((d[s[i]] % mod) + (x % mod)) % mod;
    }

    // for (int i = 97; i <= 99; i++) cout << d[i] << ' ';
    // cout << '\n';

    int c = 1;
    for (int i = 97; i <= 122; i++)
    {
        if (d[i] == 0) continue;
        c = ((d[i] % mod) * (c % mod)) % mod;
        // cout << d[i] << ' ';
    }
    // cout << '\n';
    cout << c;
}
/*
aba
5
x = 1, y = 2
abaaba
4 2
*/