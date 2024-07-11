#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    int med = a[(n-1) >> 1];

    int res = 0;
    for (int i = (n-1) >> 1; i < n; i++) {
        if (a[i] != med) break;
        res++;
    }

    cout << res;

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}