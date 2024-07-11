#include <iostream>
using namespace std;

#define int long long

const int N = 5e4 + 1;
int minPrime[N];
void minprime() {
    for (int j = 2; j < N; j += 2) {
        if (minPrime[j] == 0) minPrime[j] = 2;
    }
    for (int i = 3; i * i < N; i += 2) {
        if (minPrime[i] == 0) for (int j = i * i; j < N; j += i) {
            if (minPrime[j] == 0) minPrime[j] = i;
        }
    }
    for (int i = 2; i < N; i++) {
        if (minPrime[i] == 0) minPrime[i] = i;
    }
}

int mod, q, l, r;
int nt[N];

void solve() {
    for (int i = 2; i <= r; i++) nt[i] = 0;

    for (int i = l; i <= r; i++) {
        int ii = i;
        while (ii > 1) nt[minPrime[ii]]++, ii /= minPrime[ii];
    }
    int ans = 1;
    for (int i = 2; i <= r; i++) {
        if (minPrime[i] == i) (ans *= (nt[i] + 1)) %= mod;
    }
    cout << ans << '\n';
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("j.inp", "r", stdin);
    freopen("j.out", "w", stdout);
    #endif

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    minprime();

    cin >> mod >> q; while (q--) {
        cin >> l >> r;
        solve();
    }
}