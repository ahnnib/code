#include <iostream>
#include <map>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

void solve() {
    int n, k; see(n, k);
    int c[n]; seea(c, 0, n-1);

    map<int, int> dpp; for (int x : c) dpp[x]++;

    for (auto i : dpp) {
        if (i.second >= k && n >= k) { // rút loại này đến khi còn k thẻ
        // khi đó rút hết k thẻ thì sẽ thêm đc đủ k thẻ loại khác để rút những loại khác. Tiếp tục quá trình đến khi còn k - 1 thẻ
            cout << k - 1 << '\n';
            return;
        }
    }

    cout << n; // ko có thẻ nào đủ để rút -> đáp án là n
    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}