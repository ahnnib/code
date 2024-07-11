#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    vector<int> le, chan;
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] % 2 && le.size() < 2) le.push_back(a[i]);
        if (!(a[i] % 2) && chan.size() < 2) chan.push_back(a[i]);
    }

    int sum1 = 0, sum2 = 0;
    for (int i : le) sum1 += i;
    for (int i : chan) sum2 += i;

    if (le.size() < 2 && chan.size() < 2) cout << -1;
    else if (le.size() < 2) cout << sum2;
    else cout << max(sum1, sum2);
}
