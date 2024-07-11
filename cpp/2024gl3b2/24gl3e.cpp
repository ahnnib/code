#include <iostream>
#include <math.h>
using namespace std;

#define int long long

signed main()
{
    long double n, k; cin >> n >> k;

    int trau = 0;
    for (int i = k; i >= 1; i--) {
        cout << i << "," << ceil(n/i) << ' ';
        trau += ceil(n/i);
    }
    cout << '\n';

    int ans = 0;
    long double l = 1, r, cur = n;
    while (1) {
        r = n / (cur+1) - 1;
        ans += (l - r) * cur;
        cout << l << ' ' << r << ' ' << cur << '\n';
        cur++;
        l = r + 1;
    }
    cout << '\n' << trau << ' ' << ans;
}
/*
l: số nhỏ nhất sao cho n / l = cur
r: số lớn nhất sao cho n / r = cur
tìm số cuối cùng sao cho n / i = k
-> n = k * i

n = 50, k = 3
biên trái = k = 3
số hiện tại = ceil n / biên trái = ceil 50 / 3 = 17
biên phải = 50 / số hiện tại = 50 / 17 = 3
số lần cộng = biên phải - biên trái + 1 = 3 - 3 + 1 = 1

biên trái mới = biên phải + 1

l = ceil(n / k)
r = n / l;

50 / k = 50

*/