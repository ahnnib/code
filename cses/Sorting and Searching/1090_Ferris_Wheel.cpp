#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    sort(p, p + n);

    int l = 0, ans = 0;
    for (int r = n-1; r >= l; r--)
    {
        if (p[l] + p[r] <= x) l++;
        ans++;
    }

    cout << ans;
}