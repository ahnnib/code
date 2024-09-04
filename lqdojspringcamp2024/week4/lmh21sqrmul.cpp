#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll mod = 1e9 + 7;
const int N = 1e6 + 1;
ll n, a, mp[N], minPrime[N];

void sol() {
    for (int i = 0; i < N; i++) mp[i] = 0;
    cin >> n; for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        while (a > 1) {
            ll u = minPrime[a], cnt = 0;
            while (a % u == 0) {
                cnt++;
                a /= u;
            }
            mp[u] = max(mp[u], cnt + (cnt & 1));
        }
    }
    auto exp = [](ll a, ll b) -> ll {
        ll res = 1;
        while (b) {
            if (b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    };
    ll res = 1;
    for (int i = 2; i < N; i++) {
        res = res * exp(i, mp[i]) % mod;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 2; i < N; i++) minPrime[i] = i;
    for (int i = 2; i*i < N; i++) if (minPrime[i] == i)
        for (int j = i*i; j < N; j += i) minPrime[j] = i;

    int t = 1;
    cin >> t;
    while(t--) sol();
}