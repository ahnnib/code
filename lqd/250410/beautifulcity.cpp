#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1005;
vector<int> G[N];
int color[N];

bool is_bipartite(int n) {
    fill(color, color + n + 1, -1);
    queue<int> q;
    color[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int n, m;

void sol() {
    for (int i = 1; i < N; i++) {
        G[i].clear();
    }

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (is_bipartite(n)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    freopen("beautifulcity.inp", "r", stdin);
    freopen("beautifulcity.out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--) sol();
}