#include <iostream>
using namespace std;

#define int long long

int n, k;
int a[100001];
long long s[100001];

void trau()
{
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = i + len - (len != 0); j <= n; j++)
        {
            sum += a[j];
            if (sum == 1ll * k * (j - i + 1))
                len = max(len, j - i + 1);
        }
    }
    cout << len;
}

void full()
{
    int l = 0, r = n;
    int len = 0;
    while (l <= r)
    {
                // sum           k * len
        if ((s[r] - s[l-1]) > k * (r - l + 1)) r--;
        if ((s[r] - s[l-1]) == k * (r - l + 1)) len = max(len, r - l + 1);

    }

    cotu << len;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("average.inp", "r", stdin);
    freopen("average.out", "w", stdout);
    #endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i],
        s[i] = s[i-1] + a[i];

    trau();
}
/*
3 2
1 3 4

*/