#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const int N = 3e6 + 1;
int a, b;
int sol[N]; bool com[N];

void solve() {
    cin >> a >> b;
    cout << sol[b] - sol[a-1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("SPRIME.INP", "r", stdin);
    freopen("SPRIME.OUT", "w", stdout);

    com[0] = com[1] = 1;
    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;
    int sum, ii;
    for (int i = 2; i < N; i++) {
        if (!com[i]) {
            ii = i, sum = 0; while (ii) sum += ii%10, ii /= 10;
            sol[i] = sol[i-1] + (sum % 5 == 0);
        }
        else sol[i] = sol[i-1];
    }

//    for (int i = 1; i <= 10; i++) cout << com[i] << ' '; cout << '\n';
//    for (int i = 1; i <= 10; i++) cout << sol[i] << ' '; cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
