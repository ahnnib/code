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
    string s; cin >> s;

    // gặp số 0: chi phí để chuyển qua toàn bộ số 1 phía trước: (số số 1) + 1
    int cnt1 = 0; ll res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') cnt1++;
        if (s[i] == '0' && cnt1 > 0) res += cnt1 + 1;
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