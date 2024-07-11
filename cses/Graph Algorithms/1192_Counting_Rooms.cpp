#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

int n, m;
bool vis[1001][1001];
char map[1001][1001];

void search(int x, int y)
{
    vis[x][y] = 1;
    if (!vis[x-1][y] && x-1 >= 0 && map[x-1][y] == '.') search(x-1, y);
    if (!vis[x+1][y] && x+1 < n && map[x+1][y] == '.') search(x+1, y);
    if (!vis[x][y-1] && y-1 >= 0 && map[x][y-1] == '.') search(x, y-1);
    if (!vis[x][y+1] && y+1 < m && map[x][y+1] == '.') search(x, y+1);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
            cin >> map[i][j];

    // debug
    int room = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (map[i][j] == '.' && !vis[i][j]) search(i, j), room++;
    }
    cout << room;
}
/*
#include <iostream>
#include <queue>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

int n, m;
bool vis[1000][1000];
char G[1000][1000];

const pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs(int x, int y) {
    queue< pair<int, int> > q;

    q.push({x, y});
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_u = u + dir[i].first, new_v = v + dir[i].second;
            // cout << new_u << ' ' << new_v << '\n';

            if (new_u < 0 || new_u >= n) continue;
            if (new_v < 0 || new_v >= m) continue;
            if (G[new_u][new_v] == '#') continue;
            if (vis[new_u][new_v]) continue;

            vis[new_u][new_v] = 1;
            q.push({new_u, new_v});
        }
    }
}

signed main()
{
    see(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) see(G[i][j]);
    }

    // bfs(1, 4);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '.' && !vis[i][j]) {
                // cout << i << ' ' << j << '\n';
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;

}
*/