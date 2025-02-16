#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

struct Rec {
    int x1, y1, x2, y2;
};

bool check(Rec &a, Rec &b) {
    if (b.y1 < a.y2) {
        // left case
        if (b.x1 < a.x1 && a.x1 < b.x2) return true;
        // right case
        if (b.x1 < a.x2 && a.x2 < b.x2) return true;
    }
    else return false;
}
void printrec(Rec x) {
    cout << x.x1 << ' ' << x.y1 << ' ' << x.x2 << ' ' << x.y2 << '\n';
}

int main() {
    freopen("pin.inp", "r", stdin);
    freopen("pin.out", "w", stdout);
    int n; cin >> n;
    Rec a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }

    sort(a, a + n, [](const Rec &x, const Rec &y) {
        return x.y1 < y.y1;
    });

    // for (int i = 0; i < n; i++) {
    //     cout << a[i].x1 << ' ' << a[i].y1 << ' ' << a[i].x2 << ' ' << a[i].y2;
    //     cout << '\n';
    // }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cnt += check(a[i], a[j]);
        }
    }
    cout << cnt;

    // printrec(a[0]);
    // printrec(a[1]);

    // cout << check(a[0], a[1]);

}