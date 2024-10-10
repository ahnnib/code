#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define dbg cout << "dfad\n";

const int N = 2e5 + 1;
bool com[N];
bool prime(ll n) {
    if (n <= 3) return n > 1;
    if (n%2 == 0 || n%3 == 0) return 0;
    for (ll i = 5; i*i <= n; i += 6) {
        if (n%i == 0 || n%(i+2) == 0) return 0;
    }
    return 1;
}
ll ghep(ll &a, ll &b) {
    return stoll(to_string(a) + to_string(b));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

   freopen("MPRIME.INP", "r", stdin);
   freopen("MPRIME.OUT", "w", stdout);

    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;

    int k; cin >> k;

    ll i = 2, j = 3, cnt = 0;

    while (1) {
        while (com[i]) i++;
        j = i+1; while (com[j]) j++;
        ll n = ghep(i, j);
        // cout << n << ' ' << prime(n) << '\n';
        if (prime(n)) cnt++;
        if (cnt == k) {
            cout << n;
            break;
        }
        i = j+1;
    }
}
