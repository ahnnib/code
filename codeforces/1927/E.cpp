#include <iostream>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    // even position: decreasing
    // odd position: increasing

    int ans[n] = {};
    int l = 1, r = n;
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (i % 2) ans[j] = l++;
            else ans[j] = r--;
        }
    }

    for (int i : ans) cout << i << ' ';

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) solve();
}
/*
5
2 2
3 2
10 4
1 10 2 9 3 8 4
13 4
7 4

*/