#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b, m, k;

const int sz = 3;
struct Mat {
    ll m[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.m[i][j] += (a.m[i][k] * b.m[k][j])) %= m;
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

void sol() {
    cin >> a >> b >> m >> k;
    Mat fi, cs;
    fi.m[0][0] = fi.m[0][1] = b % m;
    cs.m[0][0] = a;  cs.m[1][0] = cs.m[1][1] = 1;

    printM(fi);

    fi = fi * powM(cs, k-1);

    cout << fi.m[0][0] << '\n';
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("one4ever.inp", "r", stdin);
    // freopen("one4ever.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}