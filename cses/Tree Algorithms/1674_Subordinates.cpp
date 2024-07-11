#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 1;
int n;
int sz[N];
vector<int> tree[N];

void dfs(int u)
{
    sz[u] = 1;
    for (auto node : tree[u])
    {
        dfs(node);
        sz[u] += sz[node];
    }
}

int main()
{
    cin >> n;

    for (int boss = 2; boss <= n; boss++)
    {
        int u;
        cin >> u;
        tree[u].push_back(boss);
    }

    dfs(1);

    for (int nv = 1; nv <= n; nv++)
    {
        cout << sz[nv]-1 << ' ';
    }
}
