#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxh = 1e4 + 1;
bool vis[705][705];
int h[705][705];
int n, m;

void search(int x, int y)
{

    if (vis[x][y]) return;
    if (x < 0 || x >= n || y < 0 || y >= n) return;

    vis[x][y] = 1;

    if (h[x-1][y] <= h[x][y]) search(x-1, y);
    if (h[x+1][y] <= h[x][y]) search(x+1, y);
    if (h[x][y-1] <= h[x][y]) search(x, y-1);
    if (h[x][y+1] <= h[x][y]) search(x, y+1);
    if (h[x+1][y+1] <= h[x][y]) search(x+1, y+1);
    if (h[x-1][y-1] <= h[x][y]) search(x-1, y-1);
    if (h[x-1][y+1] <= h[x][y]) search(x-1, y+1);
    if (h[x+1][y-1] <= h[x][y]) search(x+1, y-1);
}

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return h[a.first][a.second] > h[b.first][b.second];
}

int main()
{
    cin >> n >> m;
    vector< pair<int, int> > nodes;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        cin >> h[i][j],
        nodes.push_back({i, j});


    sort(nodes.begin(), nodes.end(), cmp);

    int ans = 0;
    for (pair<int, int> i : nodes)
    {
        if (!vis[i.first][i.second]) search(i.first, i.second), ans++;
        // cout << i.first << ' ' << i.second << '\n';
    }

    cout << ans;
}