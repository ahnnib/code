#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long k;
    int q; cin >> q; while (q--) {
        cin >> k;
        if (k == 0) cout << "1 ";
        else cout << (k % mod * 2) % mod << ' ';
    }
}