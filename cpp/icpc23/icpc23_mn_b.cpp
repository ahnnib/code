#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long
#define int long long

signed main()
{
    int n, k; cin >> n >> k;

    if (n < 10 && k == 1) return cout << n, 0;

    int cnt[10] = {};
    for (int i = 9; i >= 2; i--) {
        while (n % i == 0) {
            n /= i;
            cnt[i]++;
        }
    }

    int len = 0; for (int i = 2; i <= 9; i++) len += cnt[i];
    if (n > 1) return cout << -1, 0;
    if (len > k) return cout << -1, 0;

    for (int i = len; i < k; i++) {
        cout << 1;
    }
    for (int i = 2; i <= 9; i++) while (cnt[i]--) cout << i;
}