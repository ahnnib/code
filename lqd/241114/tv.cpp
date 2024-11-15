#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, L, a[200][20000];
const ll mod = 1e9;

int get(int i, int x) {
    int l = 0, r = L-1, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (a[i][mid] > x) r = mid - 1;
        else l = mid + 1;
    }
    return r - 0 + 1;
}

int main() {
    freopen("tv.inp", "r", stdin);
    freopen("tv.out", "w", stdout);
    cin >> n >> L;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < L; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int l = 1, r = mx, mid;
            while (l <= r) {
                mid = l + r >> 1;
                if (get(i, mid) + get(j, mid) >= L)
                    r = mid - 1;
                else l = mid + 1;
            }
            (res += (ll)l) %= mod;
        }
    }
    cout << res;
}