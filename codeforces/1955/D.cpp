#include <iostream>
#include <unordered_map>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";

void solve() {
    int n, m, k; see(n, m, k);
    int a[n], b[m];
    seea(a, 0, n-1); seea(b, 0, m-1);

    unordered_map<int, int> dppb, dppa; for (auto x : b) dppb[x]++;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        dppa[a[i]]++;
        if (dppa[a[i]] <= dppb[a[i]]) cnt++;
    }
    // if (cnt >= k) put(0);
    int res = cnt >= k;
    for (int i = m; i < n; i++) {
        int j = i - m;
        if (dppa[a[j]] <= dppb[a[j]]) cnt--;
        dppa[a[j]]--; dppa[a[i]]++;
        if (dppa[a[i]] <= dppb[a[i]]) cnt++;
        if (cnt >= k) res++;
    }
    putl(res);
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}