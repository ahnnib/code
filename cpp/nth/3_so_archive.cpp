// so thu n chia het cho a hoac b hoac c
#include <iostream>
#include <algorithm>
using namespace std;

#define debug cout << "dfad\n";
#define int long long
#define gcd __gcd
#define lcm(a, b) (a * b / gcd(a, b))

int a, b, c, n; long long abc, ab, bc, ca;
int cal(long long x) // số số t/m <= x
{
    return x / a + x / b + x / c \
           - x / ab - x / bc - x / ca \
           + x / abc;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
    // {
        cin >> a >> b >> c >> n;

        cout << "LAUNCHING DEBUGGER...\n";
        abc = lcm(lcm(a, b), c);
        ab = lcm(a, b); bc = lcm(b, c); ca = lcm(c, a);

        int t = abc / a + abc / b + abc / c - 2; // số lượng số trong 1 chu kì
        int d = n / t; // số chu kì
        // long long l = lcm * d, r = min(a, min(b, c)) * n, mid;
        long long l = 1, r = 1e18, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (cal(mid) >= n) r = mid - 1;
            else l = mid + 1;
            cout << l << ' ' << r << ' ' << mid << ' ' << cal(mid) << '\n';
        }

        cout << "EXITING DEBUGGER...\n";
        cout << l << '\n';
    // }
}
/*
95488800 98774541 37433736 504643079
found:    22634968843955804
expected: 22634968844099760
*/