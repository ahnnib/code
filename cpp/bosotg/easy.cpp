#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 2; i <= n-1; i++)
    {
        long long t = n - i + 1;
        if (i + i > n) t = i;
        (ans += (((n - 1) - t + 1)));
        // cout << t << '\n';
    }
    cout << ans;
}
/*
k = 4
1 2 3 4
i = 2
j = 3

i = 3
j = 3

*/