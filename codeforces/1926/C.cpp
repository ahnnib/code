#include <iostream>
using namespace std;

#define int long long

const int MAX = 2e5 + 7;
int f[MAX];

void pp() {
    f[0] = 0;
    for (int i = 1; i < MAX; i++) {
        int ii = i;
        while (ii) f[i] += ii % 10, ii /= 10;
        f[i] += f[i-1];
    }
}

void solve() {
    int n; cin >> n; cout << f[n] << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    pp();

    int t; cin >> t; while (t--) {
        solve();
    }
}