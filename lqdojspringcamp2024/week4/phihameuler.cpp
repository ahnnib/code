#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 1e7 + 1;
ll cnt[N], phi[N];
int main() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) phi[i] = i;
    for (ll i = 2; i <= n; i++) if (phi[i] == i)
        for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;

    for (int i = 1; i <= n; i++) cnt[phi[i]]++;
    ll res = 0; for (int i = 1; i < N; i++) res += cnt[i] * (cnt[i]-1) / 2;
    cout << res;
}