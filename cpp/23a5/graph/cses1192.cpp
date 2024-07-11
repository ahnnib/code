#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

int n, m;
bool vis[1001][1001];
char map[1001][1001];

void search(int x, int y)
{
    vis[x][y] = 1;
    if (!vis[x-1][y] /*&& x-1 >= 1*/ && map[x-1][y] == '.') search(x-1, y);
    if (!vis[x][y-1] /*&& y-1 >= 1*/ && map[x][y-1] == '.') search(x, y-1);
    if (!vis[x+1][y] /*&& x+1 <= n*/ && map[x+1][y] == '.') search(x+1, y);
    if (!vis[x][y+1] /*&& y+1 <= m*/ /*💀*/ && map[x][y+1] == '.') search(x, y+1);
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