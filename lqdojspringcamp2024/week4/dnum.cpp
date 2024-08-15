#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int a, b; while (cin >> a >> b) {
        int t = __gcd(a, b);
        int c = a / t, d = b / t;
        int res = 0;
        for (int i = 2; i*i <= c; i++) {
            if (c % i == 0) while (c % i == 0) c /= i, res++;
        }
        for (int i = 2; i*i <= d; i++) {
            if (d % i == 0) while (d % i == 0) d /= i, res++;
        }
        res += (c > 1) + (d > 1);
        cout << res << '\n';
    }
}
