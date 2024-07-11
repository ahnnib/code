#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        int mmin = min(a[i], a[i+1]), mmax = max(a[i], a[i+1]);
        for (int j = i+1; j < n; j++)
        {
            mmax = max(mmax, a[j]); mmin = min(mmin, a[j]);
            ans += mmax - mmin;
        }
    }
    cout << ans;

}
/*
0 1 0 6
0 1 1 6
*/