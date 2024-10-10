#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const int N = 1e7 + 1;
int a, b;
int sol[N]; bool com[N];

void solve() {
    cin >> a >> b;
    cout << sol[b] - sol[a-1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("PCOUNTAB.INP", "r", stdin);
    freopen("PCOUNTAB.OUT", "w", stdout);

    com[0] = com[1] = 1;
    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;
    for (int i = 2; i < N; i++) {
        sol[i] = sol[i-1] + (!com[i]);
    }

    int t = 1;
    cin >> t;
    while(t--) solve();
}

