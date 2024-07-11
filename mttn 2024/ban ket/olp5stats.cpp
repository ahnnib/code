#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define int long long

signed main()
{
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    map<int, int> cnt;
    double avg = 0;
    int dem = 0, mode;
    for (int i = 0; i < n; i++) {
        avg += a[i]; // avg
        cnt[a[i]]++; if (dem < cnt[a[i]]) dem = cnt[a[i]], mode = a[i]; // mode
    }
    avg = avg / n;

    double sigma = 0;
    for (int i = 0; i < n; i++) { // sigma
        sigma += (a[i] - avg) * (a[i] - avg);
    }
    sigma = sqrt(sigma / n);

    cout << a[n-1] << '\n';
    cout << a[0] << '\n';
    cout << fixed << setprecision(12) << avg << '\n';
    cout << a[n>>1] << '\n';
    cout << mode << '\n';
    cout << fixed << setprecision(12) << sigma;

}