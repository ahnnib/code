#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

int n, a[(int)1e5 + 1];

void sub1() {
    int cnt = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (a[j] - a[i] == a[k] - a[j]) cnt++;
            }
        }
    }
    cout << cnt;
}
void sub3() {
    cout << n * (n - 1) * (n - 2);
}
void sub2() {
    int cnt = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            int k = a[j] + a[j] - a[i];
            int t1 = lower_bound(a + j + 1, a + n, k) - a,
                t2 = upper_bound(a + j + 1, a + n, k) - a;
            cnt += t2 - t1;
        }
    }
    cout << cnt;
}
void sub4() {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i : a) {
        if (i == 1) cnt1++;
        if (i == 2) cnt2++;
        if (i == 3) cnt3++;
    }
    cout << cnt1 * cnt2 * cnt3;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("triple.inp", "r", stdin);
    freopen("triple.out", "w", stdout);
    #endif

    bool s3 = 1;
    int s4 = 0;
    cin >> n; for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] != 1) s3 = 0;
        s4 = max(s4, a[i]);
    }

    sort(a, a + n);

    if (s3) sub3();
    else if (s4 == 3) sub4();
    else if (n <= 100) sub1();
    else if (n <= 2000) sub2();
}