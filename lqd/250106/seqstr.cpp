#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int cnt[21][300001]; // cnt[len][i]: so luong xau do dai len tinh toi vi tri i
string s[300001];
int main() {
    freopen("seqstr.inp", "r", stdin);
    freopen("seqstr.out", "w", stdout);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        cnt[s[i].size()][i] = 1;
    }

    for (int len = 0; len <= 20; len++) {
        for (int i = 2; i <= n; i++) {
            cnt[len][i] += cnt[len][i-1];
        }
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int len = s[i].size();
        int j = min(i + k, n);
        res += cnt[len][j] - cnt[len][i];
    }

    cout << res;
}