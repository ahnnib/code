#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 1e6 + 1;
int cnt[N]; void sieve() {
    for (int i = 2; i*i < N; i++) if (!cnt[i])
        for (int j = i*i; j < N; j += i) cnt[j] = 1;
    cnt[2] = 1; for (int i = 3; i < N; i++) cnt[i] = cnt[i-1] + !cnt[i];
}
ll dmt(ll x) {
    return cnt[(ll)sqrt(x/9)];
}
void solve() {
    ll a, b; cin >> a >> b;
    cout << dmt(b) - dmt(a-1) << '\n';
}
/*
x = k^2 -> 3 uoc
x = k^2 * u^2 -> 9 uoc
-> x = (k*u)^2 (k, u nguyen to, k < u)
vi 3 | x nen k = 3
-> x = (3u)^2 = 9u^2
36 225 441 1089 1521 2601 3249 4761 6561 7569 8649
6  15  21  33   39   51
4 25 49 121 169 289 361 529 729 841 961
2 5  7  11  13  17  21  23  27  29  31
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dmt.inp", "r", stdin);
    freopen("dmt.out", "w", stdout);

    sieve();

    int t = 1;
    cin >> t;
    while(t--) solve();

    // for (int i = 1; i <= 100; i++) cout << cnt[i] << ' ';
    // for (int i = 0; i <= 10000; i += 3) {
    //     int cnt = 0; for (int j = 1; j <= i; j++) if (i % j == 0) cnt++;
    //     if (cnt == 9) cout << i / 9 << ' ';
    // }
}