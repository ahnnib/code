#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const ll mod = 1e9 + 7;

ll pow(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll n;
void sol() {
    cin >> n;
    if (n <= 1) cout << 0;
    else cout << pow(2, n-1) - 2;
    cout << '\n';
}

int main() {
    freopen("cperm.inp", "r", stdin);
    freopen("cperm.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}