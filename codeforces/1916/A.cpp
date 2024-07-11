#include <iostream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k; cin >> n >> k;
        long long b[n], x = 1;
        for (int i = 0; i < n; i++) cin >> b[i], x *= b[i];

        if (2023 % x) cout << "NO\n";

        else{
        cout << "YES\n";
        cout << 2023 / x; k--;
        while (k > 0) cout << ' ' << 1, k--;
        cout << '\n';
    }}
}