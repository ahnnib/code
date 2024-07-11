#include <iostream>
#include <algorithm>
using namespace std;

#define s first
#define e second

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    // sort theo tổng
    if (a.s + a.e == b.s + b.e) {
        // sort theo e
        if (a.e == b.e) {
            // sort theo s
            return a.s > b.s;
        }
        return a.e > b.e;
    }
    return a.s + a.e > b.s + b.e;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("trochoi.inp", "r", stdin);
    freopen("trochoi.out", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    pair<int, int> a[n];

    int max_e = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].e;
        max_e = max(max_e, a[i].e);
    }

    sort(a, a + n, cmp);

    // cout << '\n';
    // for (pair<int, int> i : a) cout << i.s << ' ' << i.e << '\n';

    int i; long long res = 0;
    for (i = 0; i < n && m > 0; i++) {
        if (a[i].s + a[i].e <= max_e) break;
        res += a[i].s + a[i].e; m--;
    }
    // cout << res << ' ' << i << '\n';
    res += 1ll * m * max_e;

    cout << res;
}
/*
sort theo s + e rồi đến e giảm dần

lấy lần đầu các kĩ năng đến khi nào S = s_i + e_i < e -> lấy e lớn nhất
cặp (s, max_e) chắc chắn đc lấy (vì ta lấy S đến khi nào S < e)

2 2
1 100
10000000 1


10000102
*/