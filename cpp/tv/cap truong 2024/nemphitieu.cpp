#include <iostream>
using namespace std;

#define int long long

int vong(int a, int b) {
    if (a == 6 && b == 6) return 5;
    if (a > 6) a = 10 - a + 1;
    if (b > 6) b = 10 - b + 1;
    return min(a, b);
}

void solve() {
    char bang[11][11];
    int res = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> bang[i][j];
            if (bang[i][j] == 'X') res += vong(i, j);
        }
    }

    cout << res;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}