#include <iostream>
using namespace std;

void solve() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n-1; i++) {
        int t = min(a[i-1], min(a[i]>>1, a[i+1]));
        a[i-1] -= t; a[i] -= t<<1; a[i+1] -= t;
    }

    bool c = 1;
    for (int i : a) if (i != 0) {c = 0; break; }
    cout << (c ? "YES" : "NO");

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