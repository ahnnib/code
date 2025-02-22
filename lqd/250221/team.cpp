#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

struct P {int a, b; };

int main() {
    int n; cin >> n;
    P p[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i].a >> p[i].b;
    }

    sort(p + 1, p + 1 + n, [](const P &x, const P &y) {
        if (x.b == y.b) {
            return x.a < y.b;
        }
        return x.b < y.b;
    });

    int mn[n+1] = {}, L[n+1] = {};
    mn[1] = p[1].a;
    for (int i = 2; i <= n; i++) {
        mn[i] = min(mn[i-1], p[i].a);
    }
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (mn[mid] > p[i].a) l = mid + 1;
            else r = mid - 1;
        }
        L[i] = l;
    }
    int s[n+1] = {}, d[n+1] = {};
    d[0] = -2e9;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i-1] + p[i].b;
        d[i] = max(d[i-1], p[i].b - p[i].a);
    }


    for (int i = 1; i <= n; i++) cout << p[i].a << ' ' << p[i].b << '\n';
    for (int i = 1; i <= n; i++) cout << L[i] << ' '; cout << '\n';
    for (int i = 1; i <= n; i++) cout << s[i] << ' '; cout << '\n';
    for (int i = 1; i <= n; i++) cout << d[i] << ' '; cout << '\n';



    int res = 2e9;
    for (int k = 1; k <= n; k++) {

        int ia = L[k];
        if (ia > k) {
            res = min(res, p[ia].a + s[k-1]);
        }
        else {
            res = min(res, s[k] - d[k]);
        }
        cout << res << '\n';
    }

}