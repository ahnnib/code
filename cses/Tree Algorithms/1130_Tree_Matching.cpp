#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2e5 + 1;
vector<int> dsk[MAX];
int dp[MAX][2]; // 0/1: not take/take edge v -> u

void dfs(int v, int p)
{
    for (int u : dsk[v])
    {
        if (u != p)
        {
            dfs(u, v);
            dp[v][0] += max(dp[u][0], dp[u][1]);
        }
    }
    for (int u : dsk[v])
    {
        if (u != p)
        {
            dp[v][1] = max(dp[v][1], dp[u][0] + 1 + dp[v][0] - max(dp[u][0], dp[u][1]));
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        dsk[a].push_back(b); dsk[b].push_back(a);
    }

    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]);
}