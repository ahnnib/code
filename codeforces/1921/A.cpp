#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        pair<int, int> p[4];
        for (int i = 0; i < 4; i++) cin >> p[i].first >> p[i].second;
        sort(p, p + 4);

        int t = p[1].second - p[0].second;
        cout << t * t << '\n';
    }
}
