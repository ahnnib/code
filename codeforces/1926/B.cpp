#include <iostream>
using namespace std;


void solve() {
    int n; cin >> n;
    char a[n+1][n+1] = {};
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (a[i][j] == '1') {
            if ((a[i+1][j-1] == '1' && a[i+1][j+1] == '1') || (a[i][j+1] == '1' && a[i+1][j] == '0')) { cout << "TRIANGLE\n"; return; }
            else { cout << "SQUARE\n"; return; }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}