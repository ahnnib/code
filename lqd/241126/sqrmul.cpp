#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;
const int N = 1e6 + 1;
int minPrime[N];
int n, a[N];

// map<int, int> cnt, cnt_a;

void pp() {
    for (int i = 2; i*i < N; i++)
        if (minPrime[i] == 0) for (int j = i*i; j < N; j += i)
            if (minPrime[j] == 0) minPrime[j] = i;
    for (int i = 2; i < N; i++)
        if (minPrime[i] == 0) minPrime[i] = i;
}
ll exp(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) (res *= a) %= mod;
        (a *= a) %= mod;
    }
    return res;
}


void sol() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        map<int, int> cnt_a;
        while (a[i] > 1) {
            cnt_a[minPrime[a[i]]]++;
            a[i] /= minPrime[a[i]];
        }

        for (auto &pair : cnt_a) {
            cnt[pair.first] = max(cnt[pair.first], pair.second);
        }

    }

    ll res = 1;
    for (auto &i : cnt) {
        res *= exp(i.first, i.second + (i.second & 1));
        res %= mod;
    }

    cout << res << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("sqrmul.inp", "r", stdin);
    freopen("sqrmul.out", "w", stdout);
    pp() ;
    int t = 1;
    cin >> t;
    while(t--) sol();
}