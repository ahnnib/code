#include <iostream>
#include <algorithm>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

bool maximize(long long &x, long long y) {
    if (x <= y) return x = y, 1;
    return 0;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n; see(n); int a[n]; for (int &x : a) see(x);

    sort(a, a + n, greater<int>());

    long long res = 0, price;
    for (int i = 0; i < n; i++) {
        // res = max(res, 1ll * a[i] * (i + 1));
        if (maximize(res, 1ll * a[i] * (i+1))) price = a[i];
    }

    put(res, price);
}
/*
10 25 25 50 50
50 50 25 25 10
*/
