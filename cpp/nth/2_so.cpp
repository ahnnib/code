// số thứ n chia hết cho a hoặc b

#include <iostream>
#include <algorithm>

#define lcm(a, b) (a * b / __gcd(a, b))

using namespace std;

long long lcm;
long long cal(long long &a, long long &b, long long &x)
{
    return x / a + x / b - x / lcm;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        long long a, b, n;
        cin >> a >> b >> n;

        lcm = lcm(a, b);

        long long t = lcm / a + lcm / b - 1; // số số trong 1 chu kì (lcm đc tính 2 lần -> -1)
        long long d = n / t + 1;
        long long l = a, r = lcm * d, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (cal(a, b, mid) >= n) r = mid - 1;
            else l = mid + 1;
        }

        cout << l << '\n';
    }
}
/*
2 3 10
2 3 4 6 8 9 10 12 14 15 16 18
      x         x          x
*/