#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > c;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        c.push_back({a, 1});
        c.push_back({b, -1});
    }

    sort(begin(c), end(c));

    int sum = 0, ans = 0;
    for (pair<int, int> &i : c)
    {
        sum += i.second;
        ans = max(ans, sum);
    }

    cout << ans;
}