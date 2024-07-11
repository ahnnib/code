// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e5 + 1;

// int n;
// long long a[N], b[N];

// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
//     for (long long i = -1e18; i <= 1e18; i ++)
//         for (int j = 1; j <= n; j ++)
//             if (a[j] == i) cout << a[j] << " " << b[j] << endl;
// }
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    freopen("bai2.stable.inp", "r", stdin);
    freopen("bai2.stable.out", "w", stdout);

    int n; cin >> n;
    map < long long, vector<long long> > a;
    for (int i = 0; i < n; i++)
    {
        long long x, y; cin >> x >> y;
        a[x].push_back(y);
    }

    for (auto i : a)
    {
        for (auto j : i.second) cout << i.first << ' ' << j << '\n';
    }
}