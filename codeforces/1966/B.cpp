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
    /*
    1, 1
    1, m
    n, 1
    n, n
    */
    int n, m; see(n, m);
    char g[n+1][m+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            see(g[i][j]);
        }
    }
    char tl = g[1][1], tr = g[1][m], bl = g[n][1], br = g[n][m];
    if (tl == br || tr == bl) return putl("YES"); // set 1 lần cả bảng
    // cuối cùng cũng phải set màu ở ngoài, cả bảng, k quan trọng phía trong -> chỉ xét biên ngoài
    for (int i = 1; i <= n; i++) {
        if (g[i][1] == tr && g[i][1] == br) return putl("YES");
        if (g[i][m] == tl && g[i][m] == bl) return putl("YES");
    }
    for (int j = 1; j <= m; j++) {
        if (g[1][j] == bl && g[1][j] == br) return putl("YES");
        if (g[n][j] == tl && g[n][j] == tr) return putl("YES");
    }
    put("NO");
    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}