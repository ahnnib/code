#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, n;
long long ab, bc, ca, abc;

long long lcm(long long a, long long b)
{
    long long gcd = __gcd(a, b);
    if (a / gcd > 1e18 / b) return -1;
    return a / __gcd(a, b) * b;
}

long long cal(long long x)
{
    return x / a + x / b + x / c - x / ab - x / bc - x / ca + (abc == -1 ? 0 : (x / abc));
}

int main()
{
    freopen("bai3.nth.inp", "r", stdin);
    freopen("bai3.nth.out", "w", stdout);

    int q; cin >> q;
    while (q --> 0)
    {
        cin >> a >> b >> c >> n;

        ab = lcm(a, b); bc = lcm(b, c); ca = lcm(c, a); abc = lcm(ab, c);
        long long l = 1, r = 1e8, mid, res;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (cal(mid) >= n) r = mid - 1;
            else l = mid + 1;
        }

        cout << l << '\n';
    }
}