#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    long long s[n+1] = {}, t[n+1] = {};
    int a[n]; for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = (s[i-1] + a[i]) % 3;
        t[i] = (t[i-1] + a[i]*a[i]) % 3;
    }

    long long cnt[3][3] = {};
    long long res = 0;
    for (int i = 0; i <= n; i++) {
        for (int t1 : {0, 1, 2}) for (int t2 : {0, 1, 2}) {
            if (((s[i] - t1) * (s[i] - t1) - (t[i] - t2)) % 3 == 0)
                res += cnt[t1][t2];
                // có cặp thỏa thuộc 2 mảng
        }
        cnt[s[i]][t[i]]++;
    }
    cout << res;
}
/*
\sum{ai*aj} = 1/2(\sum{a}^2 - \sum{a^2})
= 1/2((s[r] - s[l-1]) - (ssq[r] - ssq[l-1]))
*/
