#include <iostream>
using namespace std;

#define int long long

const int MAX = 2e6;
int cnt[MAX];

signed main()
{
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i + a[i] < MAX) cnt[i + a[i]]++;
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        if (j > a[j]) res += cnt[j - a[j]];
    }
    cout << res;
}
/*
a[i] + a[j] = j - i <= 2e6 - 1
-> loại mọi a[i] >= 2e6 - 1
a[i] + i = j - a[j] > 0
đếm sl a[i] + i trong mảng
for lại kt xem có gt j - a[j] nào bằng k

2 3 3 1 3 1
2     1
  3       1
      1   1
*/