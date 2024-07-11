#include <iostream>
#include <algorithm>
using namespace std;

#define Int long long

const int MAX = 1e5;
int n, m;
pair<Int, Int> nv[MAX];
Int x[MAX], y[MAX];

int tknp(Int x)
{
    int l = 0, r = n-1, mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (nv[mid].first > x) r = mid - 1;
        else if (nv[mid].first == x) break;
        else l = mid + 1;
    }
    return mid;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> nv[i].first >> nv[i].second;
    for (int i = 0; i < m; i++) cin >> x[i];
    for (int i = 0; i < m; i++) cin >> y[i];

    sort(nv, nv + n);

    Int sum[n] = {}; sum[0] = nv[0].second;
    for (int i = 1; i < n; i++) sum[i] = sum[i-1] + nv[i].second;

    for (int i = 0; i < m; i++)
    {
        // int x = tknp(a[i]),
        //     y = tknp(b[i]);

        int a = upper_bound(nv, nv + n, make_pair(x[i], (Int) 1e12)) - nv - 1,
            b = upper_bound(nv, nv + n, make_pair(y[i], (Int) 1e12)) - nv - 1;

        // cout << x << ' ' << y << '\n';
        cout << sum[a] + sum[b] << '\n';
    }
}
/*
3 2
1 3
2 4
3 7
1 2
3 2
*/