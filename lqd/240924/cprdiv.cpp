#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const int N = 6e4 + 1;
int minPrime[N];
int cnt[N];

int main() {
   freopen("CPRDIV.INP", "r", stdin);
   freopen("CPRDIV.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++) if (minPrime[i] == 0) {
        for (int j = i*i; j <= n; j += i) minPrime[j] = i;
        minPrime[i] = i;
    }

    int ii;
    // n(n-1)..(n-m+1)
    for (int i = n; i > n-m; i--) {
        ii = i;
        while (ii > 1) cnt[minPrime[ii]]++, ii /= minPrime[ii];
    }
    // m!
    for (int i = 2; i <= m; i++) {
        ii = i;
        while (ii > 1) cnt[minPrime[ii]]--, ii /= minPrime[ii];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (cnt[i] > 0);
    cout << res;
}
