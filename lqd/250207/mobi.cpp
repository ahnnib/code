// untested
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e6 + 1;
int Ox[N];

int main() {
    freopen("mobi.inp", "r", stdin);
    freopen("mobi.out", "w", stdout);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int id, val;
        cin >> id >> val;
        Ox[id] = val;
    }

    ll t = 0;
    for (int i = 0; i <= k + k; i++) {
        t += Ox[i];
    }

    ll res = t;
    for (int i = k + k + 1; i < N; i++) {
        t += Ox[i];
        t -= Ox[i - k - k - 1];
        res = max(res, t);
    }
    cout << res;
}