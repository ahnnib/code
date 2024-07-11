#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define int long long


signed main()
{
    freopen("schwarz.inp", "r", stdin);
    freopen("schwarz.out", "w", stdout);

    int n;
    cin >> n;

    cout << "0 " << n << ' ';

    int c = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
        {
            if (b == a) continue;
            else c++;
        }
    cout << c;
}