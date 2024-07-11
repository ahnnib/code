#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];


    // int cnt = 0;
    // map<int, int> m;
    // for (int i = 0; i < n; i++) {
    //     cnt += m[x - a[i]];
    //     m[a[i]]++;
    // }
    // cout << cnt;

    sort(a, a + n);

    // int l = n-1, r = l, cnt = 0;
    // for (int i = 0; i < n; i++) {
    //     while (l >= 0 && a[i] + a[l] >= x) l--;
    //     while (r >= 0 && a[i] + a[r] > x) r--;
    //     if (i >= l) {
    //         if (i >= r) break;
    //         else l = i;
    //     }
    //     cnt += r - (l+1) + 1;
    //     // cout << i << ' ' << l << ' ' << r << ' ' << cnt << '\n';
    //     cout << i << ' ';
    // }
    // cout << cnt;
}
/*
6 6
1 2 3 4 4 5

7 6
1 2 4 3 4 5 3
1 2 3 3 4 4 5


*/