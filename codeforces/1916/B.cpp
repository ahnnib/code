#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b; // a < b
        cin >> a >> b;

        int x = 0;
        if (b % a == 0) {
            /*
            b = a * p -> p = b / a
            x = b * p = b * b / a
            */
            x = b / a * b;
        }
        else {
            /*
            a = x / p, b = x / q
            -> gcd(a, b) = x / pq -> q = x / gcd * p = a / gcd
            x = bq
            */
            x = b / __gcd(a, b) * a;
        }

        cout << x << '\n';
    }
}