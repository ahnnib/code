#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    int a;
    int max_here = 0, max_all = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> a;
        max_here = max(a, max_here + a);
        max_all = max(max_here, max_all);
    }
    cout << max_all;
}