#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 5e5 + 5;
int n, m, b, r, u, v, kho[N], trai[N];
vector<int> G[N];
bool vis[N];
int dist[N];
queue<int> q;

void bfs(int par) {
    vis[par] = 1;
    dist[par] = 0;
    q.push(par);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int child : G[u]) {
            if (!vis[child]) {
                vis[child] = 1;
                dist[child] = dist[u] + 1;
                q.push(child);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("kholuong.inp", "r", stdin);
    freopen("kholuong.out", "w", stdout);

    cin >> n >> m >> b >> r;
    for (int i = 0; i < b; i++) {
        cin >> kho[i];
    }
    for (int i = 0; i < r; i++) {
        cin >> trai[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 0; i < b; i++) {
        q.push(kho[i]);
        vis[kho[i]] = 1; // khỏi bị trùng
    }
    for (int i = 0; i < b; i++) {
        bfs(kho[i]);
    }

    for (int i = 0; i < r; i++) {
        cout << dist[trai[i]] << ' ';
    }
}