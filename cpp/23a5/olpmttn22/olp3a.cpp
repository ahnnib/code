#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
#define debug cout << "dfad\n";

int n, t, a[3003];

void solve() {
    /*
    tg nhon: a^2 + b^2 > c^2
    tg vuong: a^2 + b^2 = c^2
    tg tu: a^2 + b^2 < c^2 && a + b > c
    x: dau tien c^2 >= a^2 + b^2
    y: dau tien c^2 > a^2 + b^2
    z: dau tien c > a + b

    */
    int cnt = 0;
    for (int i = 0; i < n-2; i++) {
        int x = i+2, y = i+2, z = y;
        for (int j = i+1; j < n-1; j++) {
            while (x < n && a[x]*a[x] < a[i]*a[i] + a[j]*a[j]) x++;
            while (y < n && a[y]*a[y] <= a[i]*a[i] + a[j]*a[j]) y++;
            while (z < n && a[z] <= a[i] + a[j]) z++;

            if (t == 1) cnt += (x-1) - (j+1) + 1;
            if (t == 2) cnt += (y-1) - x + 1;
            if (t == 3) cnt += (z-1) - y + 1;
        }
    }
    cout << cnt << "\n";
}

signed main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    solve();
}