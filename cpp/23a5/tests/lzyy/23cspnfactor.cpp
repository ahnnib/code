#include <iostream>
using namespace std;

long long f(long long n)
{
    long long ans = 0;
    for (long long i = 5; n >= i; i *= 5)
        ans += n / i;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    #else
    freopen("nfactor.inp", "r", stdin);
    freopen("nfactor.out", "w", stdout);
    #endif

    long long t;
    cin >> t;
    // cout << f(t);
    while (t--)
    {
        long long n;
        cin >> n;

        long long l = 0, r = 5e16, m, res;
        while (l <= r)
        {
            m = (l + r) >> 1;
            if (f(m) < n) l = m + 1;
            else r = m - 1;
        }

        cout << l << '\n';
    }
}