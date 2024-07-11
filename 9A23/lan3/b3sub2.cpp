#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

const ll N = 1e5 + 1;
ll n;
void solve() {
    cin >> n; ll old = n;
    if (n < 2) return;

    int d[N] = {}; vector<int> v;
    // 2 <= n < N: chạy log
    // n >= N: chạy căn
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0) n /= i, d[i]++;
        }
    }
    if (n > 1 && n < N) v.push_back(n), d[n]++, n = 1;

    // for (int i = 0; i <= n; i++) cout << d[i] << " \n"[i == n];

    int nd = v.size();
    // cout << nd << '\n';
    // debug
    // for (auto i : v) cout << i << ' ';
    // debug
    for (int i = 0; i < nd - 1; i++) {
        cout << v[i];
        if (d[v[i]] > 1) cout << '^' << d[v[i]];
        cout << '*';
    } if (nd > 0) { cout << v[nd-1]; if (d[v[nd-1]] > 1) cout << '^' << d[v[nd-1]]; }

    if (n > 1) {
        if (nd > 0) cout << '*';
        cout << n;
    }

    cout << '\n';
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
