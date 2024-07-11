#include <iostream>
#include <vector>
using namespace std;

#define debug cout << "dfad\n";

const int N = 1e5 + 7;
int n, m;
vector<int> G[N]; // adjacency list
vector<int> team(N);

bool dfs(int u, int t, int p) {
    team[u] = t;
    for (int id : G[u]) {
        if (id == p) continue;
        if (!team[id] && !dfs(id, 3 - team[u], u))
                return 0;
        if (team[id] == team[u])
            return 0;
    }
    return 1;
}
bool solve() {
    for (int id = 1; id <= n; id++) {
        if (!team[id] && !dfs(id, 1, -1))
                return 0;
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }

    if (!solve()) return cout << "IMPOSSIBLE", 0;

    for (int i = 1; i <= n; i++) cout << team[i] << ' ';
}