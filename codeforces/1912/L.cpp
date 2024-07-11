#include <iostream>
using namespace std;

void solve() {
    int n; string s; cin >> n >> s;

    int pre[n] = {}, suf[n] = {}; pre[0] = s[0] == 'L'; suf[n-1] = s[n-1] == 'L';
    for (int i = 1; i < n; i++) pre[i] = pre[i-1] + (s[i] == 'L');
    for (int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + (s[i] == 'L');

    int cntO = 0;
    for (int i = 0; i < n-1; i++) {
        cntO += (s[i] == 'O');
        if (pre[i] != suf[i+1] && i + 1 - pre[i] != n - i - 1 - suf[i+1]) {
            cout << i+1;
            return;
        }
    }
    cout << -1;

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}

O(n^2) solution

void solve() {
    int n; string s; cin >> n >> s;

    for (int i = 0; i < n-1; i++) {
        // 1 ... i, i+1 ... n
        int cntL1 = 0, cntO1 = 0;
        for (int j = 0; j <= i; j++) {
            if (s[j] == 'L') cntL1++;
            else cntO1++;
        }
        int cntL2 = 0, cntO2 = 0;
        for (int j = i+1; j < n; j++) {
            if (s[j] == 'L') cntL2++;
            else cntO2++;
        }
        if (cntL1 != cntL2 && cntO1 != cntO2) {
            cout << i + 1;
            return;
        }
    }
    cout << -1;

    cout << '\n';
}
