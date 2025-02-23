#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll a, b, m, k;

const int sz = 2;
struct Mat {
    ll M[sz][sz] = {};
} dv;
Mat operator *(const Mat &a, const Mat &b) {
    Mat res;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                (res.M[i][j] += (a.M[i][k] * b.M[k][j])) %= m;
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
void printM(Mat &M) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            cout << M.M[i][j] << " \n"[j == sz-1];
        }
    }
}
void pp() {
    for (int i = 0; i < sz; i++) dv.M[i][i] = 1;
}

void sol() {
    cin >> a >> b >> m >> k;
    Mat fi, cs;
    fi.M[0][0] = fi.M[0][1] = b % m;
    cs.M[0][0] = a % m;  cs.M[1][0] = cs.M[1][1] = 1 % m;

    fi = fi * powM(cs, k-1);

    cout << fi.M[0][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pp();
    freopen("one4ever.inp", "r", stdin);
    freopen("one4ever.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}