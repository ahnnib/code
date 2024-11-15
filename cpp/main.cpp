#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int k; cin >> k;
    ll res = 1;
    while (k) {
        res *= 10;
        k--;
    }
    cout << res;
}