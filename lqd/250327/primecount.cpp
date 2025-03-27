#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int l, r, mn = 1e9, mx = 0;

vector<bool> segment_sieve(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);
    int lim = sqrt(R);
    for (int i = 2; i <= lim; ++i)
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int main() {
    freopen("primecount.inp", "r", stdin);
    freopen("primecount.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        cin >> l >> r;
        vector<bool> prime = segment_sieve(l, r);
        int cnt = 0;
        for (int i = l; i <= r; i++) {
            cnt += prime[i - l];
        }
        cout << cnt << '\n';
    }
}