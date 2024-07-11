#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

void solve() {
    int n; string s; see(n, s);

    int cnt1 = 0;
    bool adj = 0;
    for (int i = 0; i < n; i++) {
        cnt1 += (s[i] == '1');
        if (i >= 1 && s[i] == s[i-1] && s[i] == '1') adj = 1;
    }

    if (cnt1 == 0) cout << "YES";
    else if (s.size() == 2) cout << "NO";
    else if (cnt1 == 2 && adj) cout << "NO";
    else if (cnt1 & 1) cout << "NO";
    else cout << "YES";

    cout << '\n';
}
/*

*/

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}