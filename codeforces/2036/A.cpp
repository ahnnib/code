#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = 1;
    for (int i = 1; i < n; i++) {
        int t = abs(a[i] - a[i-1]) ;
        if (!(t == 5 || t == 7)) {
            ok = 0;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}