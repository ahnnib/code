#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> h(n), t(m);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    sort(h.begin(), h.end());
    for (int i = 0; i < m; i++)
    {
        int x = t[i];
        if (x < h[0] || h.empty()) { cout << "-1\n"; continue; }

        int l = 0, r = h.size()-1, mid, res = -1;
        while (l <= r)
        {
            mid = (l + r) >> 1; // cuoi cung <=
            if (h[mid] <= t[i]) res = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << h[res] << '\n'; h.erase(h.begin() + res);
        // for (auto i : h) cout << i << ' '; cout << '\n';
    }
}
/*
5 3
5 3 7 8 5
4 8 3
3 5 5 7 8
4 -> 3
5 5 7 8
8 -> 8
5 5 7
3
*/