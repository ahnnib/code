#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n; cin >> n;
    ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    ll L[n], R[n];
    L[0] = a[0]; for (int i = 1; i < n; i++) L[i] = max(L[i-1], a[i]);
    R[n-1] = a[n-1]; for (int i = n-2; i >= 0; i--) R[i] = max(R[i+1], a[i]);

    ll res = -3e9;
    for (int i = 1; i < n-1; i++) {
        res = max(res, L[i] - a[i] + R[i]);
    }
    cout << res;
}
