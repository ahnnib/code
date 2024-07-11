#include <iostream>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            if (s[i+1] == '*') break;
        }
        if (s[i] == '@') res++;
    }
    cout << res << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}