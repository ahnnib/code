#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
pair<ll, ll> init = {-1, 0};

pair<ll, ll> dp[18][180][5130]; // sum, cnt
int w[10];
ll base[19];
bool not_coprime[180][5130]; // x, y coprime -> check[x][y] = 0

pair<ll, ll> f(vector<int> &dig, int vt, int t1, int t2, bool tight) {
    if (vt < 0) {
        if (!not_coprime[t1][t2]) return {0, 1};
        else return {0, 0};
    }
    if (tight != 1 && dp[vt][t1][t2] != init) return dp[vt][t1][t2];
    pair<ll, ll> res = {0, 0};
    int lim = tight ? dig[vt] : 9;
    for (int d = 0; d <= lim; d++) {
        pair<ll, ll> t = f(dig, vt - 1, t1 + d, t2 + w[d], tight & (dig[vt] == d));
        res.first = res.first + t.first % mod;
        res.first += 1ll * d * base[vt] % mod * t.second % mod;
        res.first %= mod;
        res.second += t.second;
        res.second %= mod;
    }
    if (!tight) dp[vt][t1][t2] = res;
    return res;
}
vector<int> get(ll x) {
    vector<int> res;
    for(; x; x /= 10) {
        res.push_back(x % 10);
    }
    return res;
}

ll l, r;
void sol() {
    cin >> l >> r;
    vector<int> dig_l = get(l-1), dig_r = get(r);
    pair<ll, ll> g2 = f(dig_r, dig_r.size()-1, 0, 0, 1);
    pair<ll, ll> g1 = f(dig_l, dig_l.size()-1, 0, 0, 1);
    cout << (g2.first - g1.first + mod + mod) % mod << '\n';
}

int main() {
    for (int i = 0; i < 18; i++)
        for (int j = 0; j < 180; j++)
            for (int k = 0; k < 5130; k++)
                dp[i][j][k] = init;
    for (int i = 1; i <= 9; i++) w[i] = w[i-1] + i*i;
    base[0] = 1; for (int i = 1; i <= 18; i++) base[i] = base[i-1] * 10 % mod;
    for (int i = 0; i < 180; i++) {
        for (int j = 0; j < 5130; j++) {
            if (__gcd(i, j) != 1) not_coprime[i][j] = true;
        }
    }

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}