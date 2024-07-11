#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...);
cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";

void solve() {
    int n, k; see(n, k); int a[n]; seea(a);

    k--;
    int x = a[k];
    int M = 0; while (M < n && a[M] <= x) M++; // số đầu tiên > x

    int res = 0;
    if (k < M) res = max(res, M - 1); // k < M -> đổi với con đầu tiên
    else {
        int win = 0;
        // đổi với con đầu tiên
        swap(a[k], a[0]);
        for (int i = 1; i < n && a[i] < x; i++) win++;
        res = max(res, win);
        // đổi với con thứ M
        swap(a[k], a[0]); swap(a[k], a[M]); win = 0;
        for (int i = M+1; i < n && a[i] < x; i++) win++;
        win += (M > 0); // thắng trận trước k
        res = max(res, win);
    }

    cout << res;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}