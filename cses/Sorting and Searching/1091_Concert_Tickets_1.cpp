#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

#define int long long

signed main()
{
    int n, m;
    cin >> n >> m;
    int h[n], t[m];
    map<int, int> cnt;
    for (int i = 0; i < n; i++) cin >> h[i], cnt[h[i]]++;
    for (int i = 0; i < m; i++) cin >> t[i];

    sort(h, h + n);


    for (int i = 0; i < m; i++)
    {
        int l = 0, r = n-1, mid, x = t[i];
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (x > h[mid]) r = mid - 1;
            else l = mid + 1;
        }

        if (cnt[h[mid]] > 0) cout << h[mid] << '\n', cnt[h[mid]]--;
        else cout << "-1\n";
    }
}
/*
5 3
5 3 7 8 5
4 8 3

3 5 5 7 8
3 8 -1

10 10
9 3 9 6 6 8 6 2 6 3
9 5 4 6 3 9 3 3 5 2

2 3 3 6 6 6 6 8 9 9

*/