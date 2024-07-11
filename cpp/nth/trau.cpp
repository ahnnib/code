#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define int long long

signed main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int cnt = 0;
    for (int i = min(a, min(b, c)); ; i++)
    {
        // debug
        if (i % a == 0 || i % b == 0 || i % c == 0)
            cnt++;
        if (cnt == n) return cout << i, 0;
    }
}
