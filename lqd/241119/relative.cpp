#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    ll cnt[10] = {};
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        int a1 = a;
        while (a1 > 0) {
            cnt[a1 % 10]++;
            a1 /= 10;
        }
    }
    ll res = 0;
    for (int i = 0; i < 10; i++) {
        // res += (cnt[i] - 1) * (cnt[i] - 2) / 2;
        cout << cnt[i] << ' ';
    }
    cout << res;
}