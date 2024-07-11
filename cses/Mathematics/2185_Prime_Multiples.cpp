#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    long long a[k];
    for (int i = 0; i < k; i++) cin >> a[i];

    long long ans = 0;
    for (long long i = 1; i < (1<<k); i++)
    {
        long long t = n;
        int c = 0;
        for (long long j = k-1; j >= 0; j--)
        {
            if (i & (1<<j)) t /= a[k - j - 1], c++;
            // else cout << 0;
        }
        // cout << "\n";
        // cout << t << ' ' << c << ' ' << 1ll * pow(-1, c + 1) * t << '\n';
        ans += 1ll * pow(-1, c + 1) * t;
    }
    cout << ans;
}