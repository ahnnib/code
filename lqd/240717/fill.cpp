#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
#define ll long long
#define ld long double
#define debug cout << "dfad\n";

const ld eps = 1e-9;

int n; ld v; struct Binh { ld b, h, w, d; } a[100001];

ld kt(ld x) {
    ld res = 0;
    for (int i = 0; i < n; i++) {
        res += min(a[i].h, max((ld)0, x - a[i].b)) * a[i].w * a[i].d;
    }
    return res;
}
int main() {
    freopen("fill.inp", "r", stdin);
    freopen("fill.out", "w", stdout);
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
    } char T; cin >> T;
    ld l = 0.0, r = (ld)2e9, mid; while (l <= r) {
        mid = (l + r) / 2.0;
        if (kt(mid) < v) l = mid + eps;
        else r = mid - eps;
    }
    cout << fixed << setprecision(2) << l;
}