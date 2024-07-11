#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int d = a[i-1] - a[i];
        if (d < 0) continue;
        ans += d; a[i] += d;
    }

    cout << ans;
}