#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

void solve() {
    int n; see(n); int a[n+1] = {}; seea(a, 1, n);

    for (int i = 1; i <= n; i++) {
        if (a[a[i]] == i) {
            cout << "2\n";
            return;
        }
    }
    cout << 3;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}