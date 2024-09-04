#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

ll n, m; bool com[1000001];

int main() {
    freopen("sumfact.inp", "r", stdin);
    freopen("sumfact.out", "w", stdout);

    cin >> n >> m;

    for (int i = 2; i*i <= n; i++) if (!com[i])
        for (int j = i*i; j <= n; j += i) com[j] = 1;

    ll res = 1;
    for (ll i = 3; i <= n; i++) {
        if (!com[i]) {
            ll cnt = 0, tmp = n;
            while (tmp > 0) {
                cnt += tmp / i;
                cnt %= m;
                tmp /= i;
            }
            res = res * (cnt + 1) % m;
        }
    }
    cout << (res - 1 + m) % m;
}
/*
(r-l+1)(l+r) = 2 n! -> (đếm số ước lẻ của n!) - 1 (trường hợp n = n)
*/