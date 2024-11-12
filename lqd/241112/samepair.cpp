#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6;

int lpf[N+5]; map<pair<ll, ll>, int> cnt;

ll bs = 521, md[] = {1000000007, 1234567891};

void pre() {
    lpf[0] = lpf[1] = 1;
    for (int x = 2; x <= N; x += 2) lpf[x] = 2;
    for (int x = 3; x <= N; x += 6) lpf[x] = 3;
    for (int x = 5; x <= N; x += 6) {
        vector<int> jump;
        if (lpf[x] == 0) jump.push_back(x);
        if (lpf[x+2] == 0) jump.push_back(x+2);
        for (auto y : jump) {
            for (int z = 1; y*z <= N; z++) {
                if (lpf[y*z] == 0) lpf[y*z] = y;
            }
        }
    }
}

pair<ll, ll> get(int n) {
    pair<ll, ll> h = make_pair(0, 0);
    while (n > 1) {
        int p = lpf[n];
        while (n%p == 0) n /= p;
        h.first = (h.first*bs+p)%md[0];
        h.second = (h.second*bs+p)%md[1];
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("samepair.inp", "r", stdin);
    freopen("samepair.out", "w", stdout);

    int l, r; cin >> l >> r; pre(); ll ans = 0;

    for (int x = l; x <= r; x++) {
        pair<ll, ll> cur = get(x);
        ans += 1ll*cnt[cur]; cnt[cur]++;
    }

    cout << ans << "\n"; return 0;
}