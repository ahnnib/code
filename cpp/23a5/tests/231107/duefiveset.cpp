#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long
#define llmin -1e18
const int N = 1e5 + 1;
int n, w1, w2;
int a[N];

void trau()
{
    int ans = llmin;
    for (int i1 = 1; i1 <= n - 4; i1++)
        for (int i2 = i1 + 1; i2 <= n - 3; i2++)
            for (int i3 = i2 + 1; i3 <= n - 2; i3++)
                for (int i4 = i3 + 1; i4 <= n - 1; i4++)
                    for (int i5 = i4 + 1; i5 <= n; i5++)
                        ans = max(ans, w1 * a[i1] + w2 * a[i2] + a[i3] + w2 * a[i4] + w1 * a[i5]);
    cout << ans;

}
void sub2()
{
    int res = llmin;
    for (int i = 3; i <= n-2; i++) // a1 a2 (i) a4 a5
        res = max(res, a[i]);
    cout << res;
}
void sub34()
{
    // w2 * a2 + a3 + w2 * a4

    // L[i]: GTLN của w[2] * a[từ 1 tới i]
    // R[i]: GLTN của w[2] * a[từ n tới i]
    int L[N], R[N];
    memset(L, -0x3f, sizeof(L));
    memset(R, -0x3f, sizeof(R));
    for (int i = 2; i <= n; i++) L[i] = max(L[i-1], w2 * a[i]);
    for (int i = n-1; i >= 2; i--) R[i] = max(R[i+1], w2 * a[i]);

    int ans = 0;
    for (int i3 = 3; i3 <= n-2; i3++)
    {
        ans = max(ans, L[i3-1] + a[i3] + R[i3+1]);
    }

    cout << ans;
}
void sub15()
{
    // (w1 * a1) + (w2 * a2) + a3 + (w2 * a4) + (w1 * a5)

    int Lw1[N], Lw2[N], Rw1[N], Rw2[N];
    memset(Lw1, -0x3f, sizeof(Lw1));
    memset(Lw2, -0x3f, sizeof(Lw2));
    memset(Rw1, -0x3f, sizeof(Rw1));
    memset(Rw2, -0x3f, sizeof(Rw2));

    // xây mảng L
    Lw1[1] = w1 * a[1];
    for (int i = 2; i <= n; i++)
    {
        Lw2[i] = max(Lw2[i-1], w2 * a[i] + Lw1[i-1]);
        Lw1[i] = max(Lw1[i-1], w1 * a[i]);
    }
    // xây mảng R
    Rw1[n] = w1 * a[n];
    for (int i = n-1; i >= 1; i--)
    {
        Rw2[i] = max(Rw2[i+1], w2 * a[i] + Rw1[i+1]);
        Rw1[i] = max(Rw1[i+1], w1 * a[i]);
    }

    int ans = 0;
    for (int i3 = 2; i3 <= n-1; i3++)
        ans = max(ans, Lw2[i3-1] + a[i3] + Rw2[i3+1]);
    cout << ans;
}

signed main()
{
    cin >> n >> w1 >> w2;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n <= 100) trau();
    else if (w1 == 0 && w2 == 0) sub2();
    else if (w1 == 0 && w2 < 0) sub34();
    else sub15(); // dp
}
