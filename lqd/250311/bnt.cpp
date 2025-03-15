#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e6 + 7;
bool com[N];
void sieve() {
    com[0] = com[1] = 1;
    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;
}

int f(int x) {
    for (int i = x; ; i++) {
        if (!com[i]) return i;
    }
}

int main() {
freopen("bnt.inp", "r", stdin);
freopen("bnt.out", "w", stdout);
    sieve();

    int n, m; cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j] = f(a[i][j]) - a[i][j];
        }
    }

    int res = 1e9;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += a[i][j];
        }
        res = min(res, cnt);
    }
    for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i][j];
        }
        res = min(res, cnt);
    }

    cout << res;
}