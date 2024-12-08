#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        bool ok = 1;
        for (int j = 0; j < n && ok; j++) {
            if (j == i) continue;
            if (abs(a[i] - a[j]) % k == 0) ok = 0;
        }
        if (ok) {
            cout << "YES\n" << i + 1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}