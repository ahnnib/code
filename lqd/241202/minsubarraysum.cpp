#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    ll a;
    ll min_here = 0, min_all = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> a;
        min_here = min(a, min_here + a);
        min_all = min(min_here, min_all);
    }
    cout << min_all;
}