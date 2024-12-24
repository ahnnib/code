#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const int N = 1e5 + 1;
int lpf[N];
void LPF() {
    for (int i = 2; i * i < N; i++) if (lpf[i] == 0)
        for (int j = i*i; j < N; j += i) lpf[j] = i;
    for (int i = 2; i < N; i++) if (lpf[i] == 0) lpf[i] = i;
}
map<ll, ll> factor(ll x) {
    map<ll, ll> res;
    while (x > 1) {
        res[lpf[x]]++;
        x /= lpf[x];
    }
    return res;
}
ll inv(ll x) {
    return x <= 1 ? x : mod - mod / x * inv(mod % x) % mod;
}

ll n, q, x, y, prod = 1;
vector<ll> a(N, 1);
map<ll, ll> res;

void sol() {
    x -= 1;
    map<ll, ll> t = factor(a[x]);
    for (auto i : t) {
        prod = prod * inv(res[i.first] + 1) % mod;
        res[i.first] -= i.second;
        prod = prod * (res[i.first] + 1) % mod;
    }
    a[x] = y;

    t = factor(a[x]);
    for (auto i : t) {
        prod = prod * inv(res[i.first] + 1) % mod;
        res[i.first] += i.second;
        prod = prod * (res[i.first] + 1) % mod;
    }
    cout << prod << '\n';
}

int main() {
    LPF();
    cin >> n >> q;
    while (q--) {
        cin >> x >> y; sol();
    }

}