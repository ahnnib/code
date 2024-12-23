#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int len = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) len++;
        else {
            if (len > 0) cnt++;
            len = 0;
        }
    }
    if (len > 0) cnt++;
    if (cnt > 1) cout << 2;
    else if (cnt == 1) cout << 1;
    else cout << 0;

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}