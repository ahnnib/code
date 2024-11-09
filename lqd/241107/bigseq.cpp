#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll k; int m; ll a[10], c[10];

const ll mod = 1e9 + 7;
const int sz = 10;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= mod;
            }
        }
    }
    return res;
}
Mat powM(Mat a, ll n) {
    Mat res = dv;
    for (; n > 0; n >>= 1) {
        if (n & 1) res = res * a;
        a = a * a;
    }
    return res;
}
void printM(Mat &m) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cout << m.m[i][j] << " \n"[j == sz-1];
        }
    }
}

ll sol(ll n) {
    if (n <= k) {
        return c[n];
    }
    Mat fi, cs;
    for (int i = 0; i < k; i++) {
        fi.m[0][i] = a[i];
    }
    for (int i = 0; i < k-1; i++) {
        cs.m[i+1][i] = 1;
    }
    for (int i = 0; i < k; i++) {
        cs.m[i][k-1] = a[i];
    }

    fi = fi * powM(cs, n - k);

    return fi.m[0][k - 1];
}

int main() {
    freopen("bigseq.inp", "r", stdin);
    freopen("bigseq.out", "w", stdout);

    for (int i = 0; i < sz; i++) dv.m[i][i] = 1;

    cin >> k >> m;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> c[i];

    for (int i = 0; i < m; i++) {
        ll n; cin >> n;
        cout << sol(n) << ' ';
    }
}