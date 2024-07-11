#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    pair<int, int> point[n];
    for (int i = 0; i < n; i++) cin >> point[i].first >> point[i].second;

    sort(point, point + n);

    int x1 = point[0].first, x2 = point[1].first;
    int y1 = point[0].second, y2 = point[1].second;

    cout << (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}