#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, a[5001];

int main() {
    freopen("tamgiac.inp", "r", stdin);
    freopen("tamgiac.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int l = j+1, r = n-1, mid;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (a[mid] < a[i] + a[j]) l = mid + 1;
                else r = mid - 1;
            }
            res += r - j;
        }
    }
    cout << res;
}