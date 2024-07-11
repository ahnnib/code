#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long ans = 0;
    for (long long i = 1; i * i <= n; i++)
    {
        ans += n / (i*i);
    }
    cout << ans;
}