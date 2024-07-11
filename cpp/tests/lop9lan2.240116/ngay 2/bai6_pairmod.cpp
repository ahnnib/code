#include <iostream>
#include <algorithm>
using namespace std;

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("bai6.pairmod.inp", "r", stdin);
    freopen("bai6.pairmod.out", "w", stdout);
    #endif

    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        long long a[n]; for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n, greater<long long>());

        int pos = 0;
        while (a[pos] == a[pos+1] && pos+1 < n) pos++;
        cout << a[pos+1] % a[pos] << '\n';
    }
}