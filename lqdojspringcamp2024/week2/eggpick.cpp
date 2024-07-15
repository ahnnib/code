#include <iostream>
using namespace std;

void solve() {
    long long n, k; cin >> n >> k;
    cout << (n % (k+1) ? "Rua Win" : "Tho Win");
    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    long long t; cin >> t; while (t--) {
        solve();
    }
}