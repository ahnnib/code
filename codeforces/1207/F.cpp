#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";
/*
3 2 3
3 9 6 5 7 1 11 4 8
1 3 4 5 6 7 8 9 11

*/
const int N = 5e5;
const int T = 300;
long long a[N+1], r[T+1][T+1]; // r[i][j]: tổng các a[k] thỏa mãn k % i == j

void solve() {
    long long t, x, y; see(t, x, y);

    // x < T: O()
    // x > T: O(q sqrt n)
    if (t == 1) {
        a[x] += y;
        for (int i = 1; i <= T; i++) {
            r[i][x % i] += y;
        }
    }
    if (t == 2) {
        if (x < T) {
            putl(r[x][y]);
        }
        else {
            long long sum = 0;
            for (int i = y; i <= N; i += x) {
                sum += a[i];
            }
            putl(sum);
        }
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}