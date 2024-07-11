#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";
#define int long long

signed main()
{
    int n; see(n);

    n *= n;

    int res = 0;
    for (int k1 = 1; k1 * k1 <= n; k1++) {
        if (n % k1 == 0) {
            int k2 = n / k1;
            if (k1 % 2 == k2 % 2 && k1 != k2) res++;
        }
    }
    cout << res;
}