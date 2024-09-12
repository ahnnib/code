#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

bool prime(int n) {
    if (n <= 3) return n > 1;
    if (n%2 == 0 || n%3 == 0) return 0;
    for (int i = 5; i*i <= n; i += 6) {
        if (n%i == 0 || n%(i+2) == 0) return 0;
    }
    return 1;
}
int main() {
    freopen("primehigher.inp", "r", stdin);
    freopen("primehigher.out", "w", stdout);
    int n; cin >> n;
    int res = 0;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (!prime(a[i])) continue;
        int j = i + 1;
        while (j < n && a[j] > a[j-1] && prime(a[j])) {
            j++;
        }
        if (j - i > res) {
            res = j - i;
            pos = j;    
        }
        i = j - 1;
    }
    cout << res << '\n';
    for (int i = pos - res; i < pos; i++) {
        cout << a[i] << ' ';
    }
}