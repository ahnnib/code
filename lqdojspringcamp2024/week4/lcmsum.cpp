// https://forthright48.com/spoj-lcmsum-lcm-sum/
#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 1e6 + 1;
ll phi[N], res[N];
void pp() {
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++) if (phi[i] == i)
        for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            res[j] += phi[i] * i;
        }
    }
}
void solve() {
    int n; cin >> n; cout << (res[n] + 1) * n / 2 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pp();

    int t = 1;
    cin >> t;
    while(t--) solve();
}