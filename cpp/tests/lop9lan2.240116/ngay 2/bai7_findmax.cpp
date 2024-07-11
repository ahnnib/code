#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a[1001], b[1001];

void sub2() {
    // P = B * (a[1] + a[2] + ... + a[k]) = B * A
    /*
    b < 0 -> A min
    b > 0 -> A max
    */
    long long A = 0, B = b[0];

    sort(a, a + n);

    if (B == 0) { cout << 0; return; }
    if (B < 0) for (int i = 0; i < k; i++) A += a[i];
    if (B > 0) for (int i = n-1; i > n-1-k; i--) A += a[i];

    cout << B * A;
}
void sub13() {}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("bai7.findmax.inp", "r", stdin);
    freopen("bai7.findmax.out", "w", stdout);
    #endif

    bool s2 = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        if (i > 0 && b[i] != b[i-1]) s2 = 0;
    }

    if (s2) sub2();
    else sub13();
}