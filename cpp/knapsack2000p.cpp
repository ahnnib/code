#include <iostream>
#include <algorithm>
using namespace std;

#define w first
#define v second

struct node {
    int w, v;
    bool operator < (const node &a) const {
        return v*a.w > w*a.v;
    }
} a[1000005];

int main()
{
    int n, m;
    cin >> n >> m;
    // pair<int, int> a[n];
    for (int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v;

    sort(a + 1, a + 1 + n);

    int dp[m + 1] = {};
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur = min(cur + a[i].w, m);
        for (int j = cur; j >= max(cur - 10, a[i].w); j--)
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
    }

    for (int i = 1; i <= m; i++) cout << dp[i] << ' ';
    // cout << *max_element(dp + 1, dp + 1 + m);
}
