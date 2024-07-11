#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        if (sqrt(n) == (long long)sqrt(n)) { cout << sqrt(n) << '\n'; continue; }
        long long ans = 0;
        long long root = sqrt(n / 2);
        for (long long i = sqrt(n / 2); i >= 1; i--)
        {
            if (n % (i * i) == 0) ans = max(ans, i * i);
        }
        cout << ans << '\n';
    }
}
// 3162.27766
/*
15 / 2 = 7.5


*/