#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

#define int long long

int n, a[100007];
int s3 = 0;

bool check(int n) {
    return 1<<(int)log2(n) == n;
}

void sub1() {
    int cnt = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            cnt += check(a[i] + a[j]);
        }
    }
    cout << cnt;
}
void sub2() {
    // int cnt[2050] = {};
    map<int, int> cnt;
    int maxsum = a[n-2] + a[n-1];
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += cnt[a[i]];
        int p = 2;
        while (p <= a[i]) p<<=1;
        while (p <= maxsum) cnt[p - a[i]]++, p<<=1;
    }

    cout << res;
}

signed main()
{
    cin >> n; for (int i = 0; i < n; i++) {
        cin >> a[i];

        s3 = max(a[i], s3);
    }

    sort(a, a + n);

    if (n <= 1000) sub1();
    else if (a[n-1] <= 1000) sub2();
    else sub2();
}