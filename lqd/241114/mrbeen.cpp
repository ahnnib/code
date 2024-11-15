#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("mrbeen.inp", "r", stdin);
    freopen("mrbeen.out", "w", stdout);
    ll c, k; cin >> c >> k;
    ll tien = 1; while (k--) tien *= 10;

    ll rem_down = c % tien;
    ll boundL = c - rem_down;
    ll rem_up = tien - rem_down;
    ll boundR = c + rem_up;

    if (boundR - c <= c - boundL) {
        cout << boundR;
    }
    else {
        cout << boundL;
    }
}