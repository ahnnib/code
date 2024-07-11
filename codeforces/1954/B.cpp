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
    int n; see(n); int a[n]; seea(a, 0, n-1);
    // tìm độ dài dãy có tất cả phần tử bằng a[0] dài nhất -> xóa khỏi mảng
    int res = n, t = a[0];
    for (int i = 0; i < n; i++) {
        int len = 0;
        while (a[i] == t) len++, i++;
        res = min(res, len);
    }
    if (res == n) cout << -1;
    else cout << res;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}