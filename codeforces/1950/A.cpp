#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

void solve() {
    int a, b, c; see(a, b, c);

    if (a < b && b < c) puts("STAIR");
    else if (a < b && b > c) puts("PEAK");
    else puts("NONE");
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}