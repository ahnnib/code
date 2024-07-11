#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 1;

int n, q;

vector < vector<int> > dsk(N + 1);
int dep[N + 1];
int cnt[N + 1];


void dfs(int fa, int u)
{
    dep[u] = dep[fa] + 1;
    for (int v : dsk[u]) if (v != fa) dfs(u, v);
}

int main()
{
    short t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int it = 0; it < n-1; it++)
        {
            int i, j;
            cin >> i >> j;

            dsk[i].push_back(j);
            dsk[j].push_back(i);
        }

        // initial value
        dep[0] = 0;
        dfs(0, 1);
        for (int i = 1; i <= n; i++) cnt[dep[i]]++;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (q >= cnt[i])
            {
                ans += cnt[i];
                q -= cnt[i];
            }
            else break;
        }

        for (int it = 0; it < q; it++)
        {
            int x;
            cin >> x;
        }
    }
}