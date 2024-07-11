#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";

void solve() {
    int a, b, c; see(a, b, c);

    if (b%3 + c < 3 && b%3) cout << -1;
    else {
    int res = a;
    res += b / 3;
    res += (b % 3 + c + 2) / 3;

    cout << res;
    }

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}