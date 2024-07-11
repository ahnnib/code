#include <iostream>
#include <map>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll n;

const ll N = 2e6 + 1;
int minPrime[N]; // 0 -> N - 1
void init() {
    for (int i = 2; i * i < N; i++) {
        if (minPrime[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                if (minPrime[j] == 0) minPrime[j] = i;
            }
        }
    }
    for (int i = 2; i < N; i++) if (minPrime[i] == 0) minPrime[i] = i;
}

void solve() {
    cin >> n; ll old = n;
    if (n < 2) return;

    int d[min(N, n+1)] = {}, ss = 0;
    // 2 <= n < N: chạy log
    // n >= N: chạy căn
    if (n >= N) {
            debug
        for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) { while (n % i == 0) n /= i, d[i]++; ss++; }
        }
    }
    else {
        debug
        while (n > 1) {
            if (d[minPrime[n]] == 0) ss++;
            d[minPrime[n]]++; n /= minPrime[n];
        }
    }

    cout << ss;
    // print
//    int i = 2, j = 1;
//    for (; i <= min(n, N-1); i++) {
//        cout << d[i] << ' ';
//    }

    cout << '\n';
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);

    init() ;

    int t = 1;
    // cin >> t;
    while (t--) solve();
}

