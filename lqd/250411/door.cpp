#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

const ll mod = 998244353;
int n, S;
vector<int> a(1000000);

void MITM() {
    auto getsum = [&](vector<ll> &v, vector<ll> &a) {
        int len = a.size();
        for (int i = 0; i < (1 << len); i++) {
            ll sum = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) sum += a[j];
            }
            v.push_back(sum);
        }
    };

    int mid = n / 2;
    vector<ll> a_left(a.begin(), a.begin() + mid);
    vector<ll> a_right(a.begin() + mid, a.begin() + n);

    vector<ll> Lsum, Rsum;
    getsum(Lsum, a_left);
    getsum(Rsum, a_right);

    unordered_map<ll, int> mp;
    for (ll i : Lsum) mp[i]++;

    ll res = 0;
    for (ll i : Rsum) {
        res += mp[S - i];
        res %= mod;
    }
    cout << res << '\n';
}

void DP() {
    vector<ll> dp(S + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = S; j >= a[i]; j--) {
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
    cout << dp[S] << '\n';
}

int main() {
    freopen("door.inp", "r", stdin);
    freopen("door.out", "w", stdout);
    cin >> n >> S;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n <= 40) MITM();
    else DP();
}
