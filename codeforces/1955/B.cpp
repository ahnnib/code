#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";

void solve() {
    int n, c, d; see(n, c, d); long long b[n*n]; seea(b);

    sort(b, b + n*n);
    // 0 1 ... n-1 | n n+1 ... 2n-1 | 2n ... | ... n*n-1
    long long a[n*n] = {}; a[0] = b[0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[n * i + j] = a[0];
            a[n * i + j] += c * i;
            a[n * i + j] += j * d;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[n * i + j] << ' ';
    //     }
    //     cout << '\n';
    // }
    sort(a, a + n*n);
    // for (auto i : a) put(i); cout << '\n';
    // for (auto i : b) put(i); cout << '\n';
    for (int i = 0; i < n*n; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES";


    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}