#include <iostream>
using namespace std;

int main()
{
    int n, k; cin >> n >> k; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int MAX = -1e9;
    pair<int, int> res;
    for (int l = 0; l < n; l++) {
        int sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            if (MAX < sum) MAX = sum, res = {l, r};
        }
    }
    cout << res.first << ' ' << res.second;
}