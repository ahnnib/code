#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

void print(int &n, bool c) {
    for (int i = 1; i <= n; i++) cout << (c ? "##" : ".."), c = !c;
}

void solve() {
    int n; see(n);


// 1/0 : ##/..
    bool c = 1;
    for (int i = 1; i <= n; i++) {
        for (int rep : {1, 2}) print(n, c), cout << '\n';
        c = !c;
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}