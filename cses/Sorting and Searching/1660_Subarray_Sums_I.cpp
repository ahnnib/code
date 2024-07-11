#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n+1];
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0, j = 0, sum = 0, ans = 0; // sliding window
    while (j < n)
    {
        sum += a[j++];
        while (sum >= x)
        {
            if (sum == x) ans++;
            sum -= a[i++];
        }
    }

    cout << ans;
}
