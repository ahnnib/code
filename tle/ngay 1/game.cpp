#include <iostream>
using namespace std;

#define int long long

signed main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);
    #endif

    int x, a, b, m, n; cin >> x >> a >> b >> m >> n;

    if (x < a && x < b) return cout << -1, 0;

    if (m < n) swap(a, b), swap(m, n);
    // A * m  + B * n = x
}
/*
gọi A là số lần bốc sỏi a
    B là số lần bốc sỏi b

số sỏi tối đa nhận đc sẽ là A * a + B * b
Số điểm tối đa là A * m + B * n
*/