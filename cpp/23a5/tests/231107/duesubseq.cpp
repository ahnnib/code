#include <iostream>
using namespace std;

int main()
{
    int n, S;
    cin >> n >> S;
    int a[n+1], s[n+1] = {};
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i-1] + a[i];

    int r = 1;
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        while (r <= n && s[r] - s[l-1] <= S) r++;
        r--;

        if (s[r] - s[l-1] <= S) ans += r - l + 1;

        // cout << l << ' ' << r << "\n";
    }

    cout << ans;

}
/*
5 9
2 8 1 6 3
2 10 11 17 20

*/