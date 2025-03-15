#include <iostream>
#include <iomanip>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e7 + 1;
ll sum[N]; int cnt[N];
void sieve() {
    for (int i = 2; i*i < N; i++) if (sum[i] == 0)
        for (int j = i*i; j < N; j += i) sum[j] = 1;
    for (int i = 2; i < N; i++) {
        cnt[i] = cnt[i-1] + (sum[i] == 0);
        sum[i] = sum[i-1] + (sum[i] == 0 ? i : 0);
    }
}

int a, b;
void sol() {
    cin >> a >> b;
    cout << fixed << setprecision(2) << double(sum[b] - sum[a-1]) / double(cnt[b] - cnt[a-1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("songto.inp", "r", stdin);
    freopen("songto.out", "w", stdout);
    sieve();
    int t = 1;
    cin >> t;
    while(t--) sol();
}