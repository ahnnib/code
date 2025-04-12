#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("pairpbro.inp", "r", stdin);
    freopen("pairpbro.out", "w", stdout);
    int n, k; cin >> n >> k;

    bool com[n+1] = {}; com[0] = com[1] = 1;
    for (int i = 2; i*i <= n; i++) if (!com[i])
        for (int j = i*i; j <= n; j += i) com[j] = 1;

    int res = 0;
    for (int i = 2; i + k <= n; i++) {
        res += com[i] + com[i + k] == 0;
    }
    cout << res;
}