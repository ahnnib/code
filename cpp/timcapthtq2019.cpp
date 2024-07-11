// ko dùng int long long đúng chỗ -> TLE
#include <iostream>
#include <algorithm>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

int n, k; ll v;
ll check(int mid) {
    ll cnt = 0; int T = min(n, mid - 1);
    for (int x = 1; x <= T; x++) {
        cnt += min(n, mid - x) / (k / __gcd(x, k));
    }
    return cnt;
}

signed main()
{
    see(n, k, v);
    int l = 1, r = 2 * n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid) < v) l = mid + 1;
        else r = mid - 1;
    }
    v -= check(l - 1);
    for (int x = 1; x <= n; x++) {
        if ((l - x) % (k / __gcd(x, k)) == 0 && l - x <= n) v--;
        if (v == 0) return putl(x, l - x), 0;
    }
}