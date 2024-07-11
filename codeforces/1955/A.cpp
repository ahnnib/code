#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";

void solve() {
    int n, a, b; see(n, a, b);
    int t1 = 2 * a,
        t2 = 1 * b; // buy 2 yogurts

    if (t1 < t2) {
        putl(a * n);
    }
    else {
        int p1 = (n - (n&1)) >> 1,
            p2 = n&1;
        p1 *= b;
        p2 *= a;
        putl(p1 + p2);
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}