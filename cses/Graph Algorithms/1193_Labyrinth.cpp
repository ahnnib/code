#include <iostream>
using namespace std;

string ans = 0;
void search(pair<int, int> a, pair<int, int> b) { // bfs

}

int main()
{
    int n, m; cin >> n >> m;
    pair<int, int> start, end;
    char map[n][m];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> map[i][j];
        if (map[i][j] == 'A') start = {i, j};
    }

    search(start, end);

    cout << ans;
}