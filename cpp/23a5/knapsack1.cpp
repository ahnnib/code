#include<bits/stdc++.h>
using namespace std;

typedef long long Int;

const int N = 105;
const int W = 1e5 + 50;

const Int INF = 1e18;

int n,sum;
int weight[N], value[N]; //trọng số & giá trị của món đồ thứ i

Int dp[N][W];
// dp(i,s): xét i phần tử đầu tiên, tổng khối lượng của các viên bi là s
// thì tổng giá trị lớn nhất là bao nhiêu?

void solve()
{
    cin >> n >> sum;
    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];
    // Cách 1:
    for (int i = 0; i <= n; i++)
        for (int s = 0; s <= sum; s++) dp[i][s] = -INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= sum; s++) {
            dp[i][s] = dp[i-1][s]; //không chọn viên bi i
            dp[i][s] = max(dp[i][s], // if s >= w[i]
                           dp[i-1][s - weight[i]] + value[i]);
        }
    }
    Int ans = 0;
    for (int s = 0; s <= sum; s++)
        ans = max(ans, dp[n][s]);
    cout << ans;
    // Cách 2 (bài 2):
    vector<Int> f(sum+1, -INF);  //tương đương  vòng for sau
    // for (int s = 0; s <= sum; s++) f[s] = -INF;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int s = sum; s >= weight[i]; s--)
            f[s] = max(f[s], f[s - weight[i]] + value[i]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#define task "WF"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	solve();
}
