#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

bool com[1000001];

int main() {
    freopen("twins.inp", "r", stdin);
    freopen("twins.out", "w", stdout);

    int n, k; cin >> n >> k;

    for (int i = 2; i*i <= n; i++) if (!com[i])
        for (int j = i*i; j <= n; j += i) com[j] = 1;

    int res = 0;
    for (int i = 2; i <= n-k; i++) {
        res += !com[i] && !com[i+k];
    }
    cout << res;
}