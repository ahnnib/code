#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 5e6 + 1;
bool com[N];
void sieve() {
    com[0] = com[1] = 1; for (int i = 2; i * i < N; i++) if (!com[i]) for (int j = i*i; j < N; j += i) com[j] = 1;
}
int main() {
    freopen("bundau.inp", "r", stdin);
    freopen("bundau.out", "w", stdout);
    sieve();
    int n; cin >> n; int a[n+1]; for (int i = 1; i <= n; i++) cin >> a[i];
    int s[n+1] = {}; for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    int res = -1;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) if (!com[s[j] - s[i-1]]) res = max(res, j-i+1);
    cout << res;
}