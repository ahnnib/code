#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    #ifndef ONLINE_JUDGE
    #else
    freopen("remove.inp", "r", stdin);
    freopen("remove.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<int> a(n+1); iota(a.begin(), a.end(), 0);
    while (!a.empty()) {
        for (int i = 0; i < a.size(); i += k) {
            cout << a[i] << ' ';
            a.erase(a.begin() + i); i--;
        }
    }
}