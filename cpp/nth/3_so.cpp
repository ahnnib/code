#include <iostream>
#include <algorithm>
using namespace std;

#define debug cout << "dfad\n";

long long a, b, c, n;
long long abc, ab, bc, ca; // lcm
long long cal(long long x)
{
    long long t;
    if (abc == -1) t = 0;
    else t = x / abc;
    return x / a + x / b + x / c \
           - x / ab - x / bc - x / ca \
           + t;
}

long long lcm(long long a, long long b)
{
    long long gcd = __gcd(a, b);
    // a * b / gcd
    // a / gcd * b > 1e18 -> a / gcd > 1e18 / b
    if (a / gcd > 1e18 / b) return -1;
    return a / gcd * b;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> n;

        ab = lcm(a, b); bc = lcm(b, c); ca = lcm(c, a);
        abc = lcm(ab, c);
        // long long t = abc / a + abc / b + abc / c - 2;
        // long long d = n / t;

        long long l = 1, r = 1e18, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (cal(mid) >= n) r = mid - 1;
            else l = mid + 1;
        }

        cout << l << '\n';
    }
}
/*
*/