#include <iostream>
#include <map>
using namespace std;

#define int long long

signed main()
{
    int n, k; cin >> n >> k;
    int res = 0;
    map<int, int> m; m[0] = 1;
    int d[n+1] = {};
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        d[i] = d[i-1] + (a & 1);
        if (d[i] >= k) res += m[d[i] - k];
        m[d[i]]++;
    }
    cout << res;
}