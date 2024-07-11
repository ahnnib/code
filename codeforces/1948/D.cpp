#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
#define debug cout << "dfad\n";

void solve() {
    string s; see(s);

    int nd = s.size();

    int res = 0;
    for (int d = 1; d <= nd>>1; d++) {
        int cnt = 0;
        for (int i = 0; i < nd-d; i++) {
            cnt += (s[i] == s[i + d]) || (s[i] == '?') || (s[i + d] == '?');
            if (i >= d) { // [l + 1, r + 1)
                cnt -= (s[i - d] == s[i]) || (s[i - d] == '?') || (s[i] == '?');
            }
            if (i >= d - 1 && cnt == d) {
                res = max(res, d<<1);
                // cout << d << '\n';
            }
        }
    }
    cout << res;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}