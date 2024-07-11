#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    long long sum[n+1] = {};
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }

    while (q --> 0)
    {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
}