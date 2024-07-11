#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int sum_div(int x) {
    int res = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) res += i + (i == x/i ? 0 : x/i);
    }
    return res;
}
pair<int, int> frac(int n, int d) {
    int gcd = __gcd(n, d);
    n /= gcd, d /= gcd;
    return {n, d};
}

signed main()
{
    int a, b; cin >> a >> b;

    pair<int, int> fa = frac(sum_div(a), a),
                   fb = frac(sum_div(b), b);

    if (fa.first == fb.first && fa.second == fb.second) cout << fa.first << '\n' << fa.second;
    else cout << -1;
}