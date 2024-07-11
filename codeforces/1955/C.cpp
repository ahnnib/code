#include <iostream>
#include <vector>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";
/*
1
4 6
5 3 3 1
1

2

1
4 5
1 2 4 3
*/
void solve() {
    int n; long long k; see(n, k); int a[n]; seea(a, 0, n-1);

    int l = 0, r = n-1, res = 0;
    while (1) {
        int t = min(a[l], a[r]);
        if (k == 0) break;
        if (l > r) break;
        if (l == r) {
            if (k >= a[l]) res++;
            break;
        }
        if (k >= 2 * t) {
            a[l] -= t;
            a[r] -= t;
            if (a[l] == 0) l++;
            if (a[r] == 0) r--;
            k -= 2 * t;
        }
        else if (k < 2 * t) {
            int tt = k / 2;
            if (k & 1) a[l] -= tt + 1; else a[l] -= tt;
            a[r] -= tt;
            k -= k;
        }
        // if (k == 0) break;
        // if (k > 0 && a[l] > 0) a[l]--, k--;
        // if (k > 0 && a[r] > 0) a[r]--, k--;
        // if (a[l] == 0) l++;
        // if (a[r] == 0) r--;
    }
    for (auto i : a) res += (i == 0);
    put(res);
    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}