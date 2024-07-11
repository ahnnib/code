#include <iostream>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

const int sz = 2;
struct mat { ll m[sz][sz] = {}; } dv, bs;
mat pow[61];
mat operator * (mat &a, mat &b) {
    mat res;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) for (int k = 0; k < sz; k++) {
        res.m[i][j] += a.m[i][k] * b.m[k][j];
        res.m[i][j] %= mod;
    }
    return res;
}
void init() {
    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;
    bs.m[0][0] = 2; bs.m[1][0] = bs.m[0][1] = 1; bs.m[1][1] = 4;
    pow[0] = bs; for (ll i = 1; i <= 60; i++) pow[i] = pow[i-1] * pow[i-1];

}
mat powm(mat a, ll n) {
    mat res = dv;
    for (int i = 0; n > 0; n >>= 1, i++) {
        if (n & 1) res = res * pow[i];
    }
    return res;
}
void printm(mat &m) { for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) cout << m.m[i][j] << " \n"[j == sz-1]; }

void solve() {
    ll n; cin >> n;
    mat fi; fi.m[0][0] = fi.m[0][1] = 1;
    mat cs = powm(bs, n-1);
    mat kq = fi * cs;
    cout << (kq.m[0][0] + kq.m[0][1]) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init() ;

    int t = 1;
    cin >> t;
    while (t--) solve();
}
/*
#define ll long long
const ll m = 1e9 + 7;
ll dp[1000001][2]; // dp[n][0/1]: số cách xây tháp 2 x n với block cuối là block liền/rời

void mod(ll &a) { a %= m; }
void init() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        dp[i][0] += 2 * dp[i - 1][0]; mod(dp[i][0]);
        dp[i][0] += dp[i - 1][1]; mod(dp[i][0]);
        dp[i][1] += dp[i - 1][0]; mod(dp[i][1]);
        dp[i][1] += 4 * dp[i - 1][1]; mod(dp[i][1]);
    }
}

void solve() {
    int n; cin >> n;
    cout << (dp[n][0] + dp[n][1]) % m << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init() ;

    int t = 1;
    cin >> t;
    while (t--) solve();
}
*/