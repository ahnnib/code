#include <iostream>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (k + 1 >= n) cout << 1;
    else cout << n;

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