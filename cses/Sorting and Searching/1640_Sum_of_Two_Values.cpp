#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    int l = 0, r = n-1;
    for (int l = 0; l < n-1; l++)
    {
        while (r > l+1 && a[l].first + a[r].first > x) r--;
        if (a[l].first + a[r].first == x) return cout << a[l].second+1 << ' ' << a[r].second+1, 0;
    }

    cout << "IMPOSSIBLE";
}