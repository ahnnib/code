#include <iostream>
using namespace std;

#define int long long

signed main()
{
    int N, M; string n;
    cin >> N >> M >> n;
    int nd = n.size();

    int t = 1;
    int ans = 0;
    for (int i = nd-1; i >= 0; i--)
    {
        // \sum{n[i] * (i+1) * t}
        (ans += (n[i] - 48) * (i+1) % M * t) %= M;
        t = (t * 10 + 1) % M;
    }

    cout << ans;
}
/*
5
0 1 2 3 4

*/