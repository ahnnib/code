#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first; // to sort by end time

    sort(a, a + n);

    int ans = 0, endtime = 0;
    for (auto i : a)
        if (i.second >= endtime)
            endtime = i.first,
            ans++;

    cout << ans;
}