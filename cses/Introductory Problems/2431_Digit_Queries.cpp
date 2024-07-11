#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define pow(a, b) round(pow(a, b))

long long digits_count(short x)
{
    return 1ll * x * 9 * pow(10, x-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    short q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;

        long long s = 0;
        short range = 1;
        while (s < k - digits_count(range))
            s += digits_count(range++);

        long long l = pow(10, range-1);

        long long digit_steps = k - s - 1;

        l += digit_steps / range;

        string ans = to_string(l);
        cout << ans[digit_steps % range] << '\n';
    }
}
/*
12345678910111213141516171819202122232425...
3
7
9
12

7
4
1
*/