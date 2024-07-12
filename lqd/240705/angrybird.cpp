#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

ll n, k, a[50000];

bool check(ll R) {
    ll d = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (d < a[i]) {
            d = a[i] + 2 * R;
            cnt++;
        }
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll l = 0, r = a[n-1], mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}