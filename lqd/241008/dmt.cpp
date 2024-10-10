#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e6 + 1;
ll a, b;
ll sol[N];

ll dmt(ll x) {
    return sol[(ll)sqrt(x/9)];
}
void solve() {
    cin >> a >> b;
    cout << dmt(b) - dmt(a-1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("dmt.inp", "r", stdin);
    freopen("dmt.out", "w", stdout);

    for (int i = 2; i*i < N; i++) if (!sol[i])
        for (int j = i*i; j < N; j += i) sol[j] = 1;
    sol[2] = 1;
    for (int i = 3; i < N; i++) sol[i] = sol[i-1] + !sol[i];

    int t = 1;
    cin >> t;
    while(t--) solve();
}