#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
const int N = 2e5 + 1;
bool mark[N][2];
void sol() {
    ll n; cin >> n;
    for (int i = 0; i <= n; i++) {
        mark[i][0] = mark[i][1] = 0;
    }
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        mark[x][y] = 1;
    }
    ll res = 0;
    for (int i = 0; i <= n; i++) {
        if (mark[i][0] + mark[i][1] == 2) {
            res += n - 2;
        }
    }
    for (int i = 1; i < n; i++) {
        if (mark[i-1][0] + mark[i][1] + mark[i+1][0] == 3) res++;
        if (mark[i-1][1] + mark[i][0] + mark[i+1][1] == 3) res++;
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}