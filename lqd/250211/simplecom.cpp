#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n; cin >> n;

    vector<int> v;
    for (int i = 2; i*i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    }
    if (n > 1) v.push_back(n);

    if (v.size() == 2) cout << "Yes";
    else cout << "No";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("simplecom.inp", "r", stdin);
    freopen("simplecom.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}