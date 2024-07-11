#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

bool DEBUG = 0;

void solve() {
    int n; string s; see(n, s);
    for (int len = 1; len <= n; len++) {
        if (n % len == 0) {
            if (DEBUG) cout << "LEN: " << len << '\n';
            int diff = 0;
            for (int i = 0; i < len; i++) {
                if (DEBUG) cout << i << ": ";
                for (int j = i + len; j < n; j += len) {
                    if (DEBUG) put(j);
                    if (s[i] != s[j]) diff++;
                }
            }
            if (DEBUG) cout << '\n';
            if (DEBUG) put(diff);
            if (diff <= 1) {
                putl(len);
                // debug
                return;
            }
            diff = 0;
            // debug
            for (int i = n - len; i < n; i++) { // check ngược lại
            // debug
                if (DEBUG) cout << i << ": ";
                for (int j = i - len; j >= 0; j -= len) {
                    if (DEBUG) put(j);
                    if (s[j] != s[i]) diff++;
                }
            }
            if (DEBUG) putl(diff);
            if (diff <= 1) {
                putl(len);
                // debug
                return;
            }
        }
    }

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}