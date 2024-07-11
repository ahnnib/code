#include <iostream>
#include <vector>
using namespace std;

#define int long long

int n, k;

pair<int, int> ss0(int n) {
    int cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0) n /= 2, cnt2++;
    while (n % 5 == 0) n /= 5, cnt5++;
    return {cnt2, cnt5};
}

signed main()
{
    cin >> n >> k;
    vector< pair<int, int> > res;
    int a; for (int i = 0; i < n; i++) {
        cin >> a;
        res.push_back(ss0(a));
    }

    int ans = 0;
    for (int i = 0; i < 1<<n; i++) {
        int cnt2 = 0, cnt5 = 0;
        for (int j = n-1; j >= 0; j--) {
            if (i & 1<<j) cnt2 += res[j].first, cnt5 += res[j].second;
        }
        ans = max(ans, min(cnt2, cnt5));
    }
    cout << ans;
}
/*
50 4 20
{1, 2}
{2, 0}
{2, 1}

15 16 3 25 9
{0, 1}
{4, 0}
{0, 2}
*/
