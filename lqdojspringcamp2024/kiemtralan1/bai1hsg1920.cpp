#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int a, b, x; cin >> a >> b >> x;
    // u + v = 0 (mod x)
    // u = -v (mod x)
    if (a < b) swap(a, b);
    ll cnt = 0;
    for (int v = 0; v <= b; v++) {
        int rem = (-v % x + x) % x;
        if (rem > a) continue;
        cnt += (a - rem) / x + 1;
    }
    cout << cnt;
}