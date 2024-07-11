#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, tc = 1; ll a[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> tc;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (tc--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) a[x] += y;
        if (t == 2) a[x] ^= y;
        if (t == 3) {
            ll sum = a[x], cnt = (sum & 1);
            for (int i = x + 1; i <= y; i++) {
                sum ^= a[i];
                cnt += (sum & 1);
            }
            cout << cnt << '\n';
        }
    }
}
