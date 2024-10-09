#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
bool com[1000001];
int main() {
    freopen("twins.inp", "r", stdin);
    freopen("twins.out", "w", stdout);

    com[0] = com[1] = 1;
    for (int i = 2; i*i < 1000001; i++) if (!com[i])
        for (int j = i*i; j < 1000001; j += i) com[j] = 1;

    int n, k; cin >> n >> k; int cnt = 0;
    for (int i = k+2; i <= n; i++) {
        if (!com[i] && !com[i-k]) cnt++;
    }
    cout << cnt;
}