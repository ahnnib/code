#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const int N = 1e7 + 1;
int a, b, ii;
int sol[N]; bool com[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("SPRIME1.INP", "r", stdin);
    freopen("SPRIME1.OUT", "w", stdout);

    com[0] = com[1] = 1;
    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;

    for (int i = 2; i < N; i++) {
        ii = i;
        while (ii && !com[ii]) ii /= 10;
        sol[i] = sol[i-1] + (ii == 0);
    }

    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        ii = i; while (ii && !com[ii]) ii /= 10;
        if (ii == 0) cout << i << '\n';
    }
}
