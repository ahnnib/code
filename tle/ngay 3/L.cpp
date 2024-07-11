#include <iostream>
using namespace std;

#define int long long

const int N = 2e5 + 7;
int n, k, x, y, a[N], b[N];

void sub1() {
    cout << a[x] + b[y];
}
void sub2() {
    int res = 0;
    for (int i : {x-1, x, x+1}) {
        res = max(res, a[i] + b[y]);
    }
    for (int j : {y-1, y, y+1}) {
        res = max(res, a[x] + b[j]);
    }
    cout << res;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
    #endif

    cin >> n >> k >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    if (k == 0) sub1();
    if (k == 1) sub2();
}