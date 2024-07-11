#include <iostream>
#include <algorithm>
using namespace std;

#define lcm(a, b) (a) / (__gcd(a, b)) * (b);

void solve() {
    long long a, b, n; cin >> a >> b >> n;

    if (a > b) { cout << "NO\n"; return; }
    if (n == 1) { cout << "YES\n"; return; }

    bool c = 1;
    while (b > a) {
        while (b > a && b % a != 0) b -= n;
        b /= n;
    }
    cout << (b == a ? "Yes" : "No");

    cout << '\n';
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("transform.inp", "r", stdin);
    freopen("transform.out", "w", stdout);
    #endif

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}