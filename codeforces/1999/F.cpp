#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 2e5 + 1;
const ll mod = 1e9 + 7;
ll fac[N], ifac[N];

ll exp(ll a, ll b) {
    ll res = 0;
    return res;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void pp() {
    fac[0] = 1; for (int i = 1; i < N; i++) fac[i] = fac[i-1] * i % mod;
    ifac[N-1] = exp(fac[N-1], mod-2);
    for (int i = N-2; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1) % mod;
}
ll nCr(int n, int k) {
    if (n < k) return 0;
    return fac[n] * ifac[k] % mod * ifac[n-k] % mod;
}
void solve() {
    ll n, k; cin >> n >> k;
    ll x = 0; for (int i = 0; i < n; i++) { bool a; cin >> a; x += a; }
    ll res = 0;
    for (int i = k / 2 + 1; i <= min(x, k); i++) {
        // res += nCr() * nCr() % mod;
        res %= mod;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pp();
    int t = 1;
    // cin >> t;
    // while(t--) solve();
    // for (int i = 0; i <= 10; i++) cout << fac[i] << ' '; cout << '\n';
    // for (int i = 0; i <= 10; i++) cout << ifac[i] << ' '; cout << '\n';
    cout << ifac[N-1];
    cout << nCr(5, 3);
}
/*
#include <iostream>
using namespace std;

const long long MAX = 2e5 + 1;
const long long mod = 1e9 + 7;

long long fact[MAX], ifact[MAX];

long long expo(long long a, long long b)
{
    if (b == 0) return 1;
    long long t = expo(a, b/2) % mod;
    t = t * t % mod;
    return t * (b % 2 ? a : 1) % mod;
}
long long nCr(long long n, long long k)
{
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main()
{
    // preprocess
    fact[0] = 1; for (long long i = 1; i < MAX; i++) fact[i] = fact[i-1] * i % mod;
    ifact[MAX-1] = 1ll * expo(fact[MAX-1], mod-2);
    for (long long i = MAX-2; i >= 0; i--) ifact[i] = ifact[i+1] * (i+1) % mod;

    // int n; cin >> n;
    // while (n--)
    // {
    //     long long a, b; cin >> a >> b;
    //     cout << nCr(a, b) << '\n';
    // }
    // cout << ifact[MAX-1];
    cout << fact[MAX-1];
}
*/