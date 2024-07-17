#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

const int N = 2e7 + 5;
bool com[N];
void sieve() {
    com[0] = com[1] = 1;
    for (int i = 2; i * i < N; i++) if (com[i] == 0)
        for (int j = i*i; j < N; j += i) com[j] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("bertran.inp", "r", stdin);
    freopen("bertran.out", "w", stdout);
    sieve();
    int n; while (cin >> n) {
        int res = 0;
        for (int i = n+1; i < 2 * n; i++) res += !com[i];
        cout << res << '\n';
    }
}