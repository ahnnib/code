// sum{1 <= i < j <= n} gcd(i, j)
#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll mod = 1e9 + 7;
const int N = 1e6 + 1;
int phi[N]; ll res[N];

void pp() {
    for (int i = 1; i < N; i++) phi[i] = i;
    for (int i = 2; i < N; i++) if (phi[i] == i)
        for (int j = i; j < N; j += i) phi[j] -= phi[j] / i;
    for (int i = 1; i < N; i++) {
        for (int j = 2; i*j < N; j++) {
            res[i*j] += 1ll * i * phi[j];
        }
    }
    for (int i = 2; i < N; i++) res[i] += res[i-1];
}
int main() {
    pp();
    int n; while (cin >> n) {
        if (n == 0) return 0;
        cout << res[n] << '\n';
    }
}