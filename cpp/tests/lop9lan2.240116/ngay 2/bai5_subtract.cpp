#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("bai5.subtract.inp", "r", stdin);
    freopen("bai5.subtract.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    long long a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<long long>());

    long long ans = 1;
    for (int i = 0; i < k; i++)
    {
        ans = (ans * ((a[i]-1) % mod)) % mod;
    }
    for (int i = k; i < n; i++)
    {
        ans = (ans * (a[i] % mod)) % mod;
    }

    cout << ans;
}