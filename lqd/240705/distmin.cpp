#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

#define x first
#define y second

int main() {
    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;

    sort(a, a + n);

    int res = 1e9;
    for (int i = 0; i < n; i++) {
        res = min(res, min(abs(a[i].x - a[i+1].x), abs(a[i].y - a[i+1].y)));
    }
    cout << res;
}