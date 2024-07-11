#include <iostream>
using namespace std;

const int N = 2e6 + 1; bool prime[N];
void sieve() {
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < N; i++) if (prime[i] == 0) {
        for (int j = i * i; j < N; j += i) prime[j] = 1;
    }
}

int solve(int x) {
    if (x < 2) return -1;
    while (prime[x]) {x--;}
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("twodiv.inp", "r", stdin);
    freopen("twodiv.out", "w", stdout);
    #endif

    sieve();

    int n; cin >> n; while (n--) {
        int a; cin >> a; cout << solve(a) << ' ';
    }
}