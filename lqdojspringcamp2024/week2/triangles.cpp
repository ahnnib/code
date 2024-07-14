#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, a[5000], f[5000], b[5000];

int main() {
    freopen("triangles.inp", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    // b[i]: cac ki tu khac nhau trong a
    // f[i]: so lan xuat hien
    int m = 0, p = 0; for (int i = 0; i <= n; i++) {
        if (i == n || a[i] != a[p]) b[m] = a[p], f[m] = i - p, m++, p = i;
    }
    ll res = 0;
    // tam giac deu: O(m)
    for (int i = 0; i < m; i++) if (f[i] >= 3) res++;
    // tam giac can: O(m)
    int j = 0;
    for (int i = 0; i < m; i++) {
        if (f[i] >= 2) {
            while (j < m && b[j] < 2 * b[i]) j++;
            res += j - 1;
        }
    }
    // tam giac khong can O(m^2)
    for (int i = 0; i < m; i++) {
        int k = i+2;
        for (int j = i+1; j < m; j++) {
            while (k < m && b[k] < b[i] + b[j]) k++;
            res += k - j - 1;
        }
    }
    cout << res;
}