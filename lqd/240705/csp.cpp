#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int j = n-1; ll res = 0;
    for (int i = 0; i < n; i++) {
        while (i < j && a[j] + a[i] > m) j--;
        if (i < j && a[i] + a[j] <= m) res += j - i;
    }
    cout << res;
}