#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

#define debug cout << "dfad\n";

// dfs
vector<int> ans; bool found;
void dfs(int beg_node, int id, vector< vector<int> > &adj, int end_node) {
    ans.push_back(beg_node);
    if (beg_node == end_node) { // base case
        found = 1;
        return;
    }
    for (int node : adj[beg_node]) {
        if (node != id) dfs(node, beg_node, adj, end_node);
        if (found) return;
    }
    ans.pop_back();
}

// dsu implementation
const int N = 2e5 + 7;
vector<int> parent(N), lvl(N);
void init(int n) {
    n += 1; // do tính từ 0
    iota(parent.begin(), parent.begin() + n, 0);
    lvl.assign(n, 0);
}
int find(int u) {
    return (parent[u] == u ? u : (parent[u] = find(parent[u])));
}
bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    // if (sz[u] < sz[v]) swap(u, v);
    // parent[v] = u;
    // sz[u] += sz[v];
    if (lvl[u] < lvl[v]) swap(u, v);
    parent[v] = u;
    if (lvl[u] == lvl[v]) lvl[u]++;
    // debug
    // for (int i = 0; i <= 15; i++) cout << parent[i] << ' '; cout << '\n';
    return 1;
}

void solve() {
    int n, m; cin >> n >> m;
    vector < pair<int, pair<int, int> > > edge(m); // w, u, v
    for (int i = 0; i < m; i++) {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }

    // cout << "{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{OUTPUT}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}\n";

    sort(edge.rbegin(), edge.rend());

    // for (auto i : edge) cout << i.first << ' ' << i.second.first << ' ' << i.second.second << '\n';

    init(n); ans.resize(0); /* path.resize(0); */ found = 0; // dsu + dfs + preparation

    pair<int, int> best_edge; int smallest_w = 2147483647;
    vector< vector<int> > adj(n + 1);

    for (auto e : edge) {
        if (!unite(e.second.first, e.second.second)) { // cạnh ni sẽ nối 2 thành phần liên thông
            best_edge = e.second;
            smallest_w = e.first;
        }
        else {
            adj[e.second.first].push_back(e.second.second);
            adj[e.second.second].push_back(e.second.first);
        }
    }

    // for (int i = 0; i <= n; i++) if (!adj[i].empty()) { cout << i << ": "; for (auto j : adj[i]) cout << j << ' '; cout << '\n'; }
    // cout << best_edge.first << ' ' << best_edge.second << '\n';

    dfs(best_edge.first, -1, adj, best_edge.second); // tìm chu trình

    // debug
    cout << smallest_w << ' ' << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }

    // init(4);
    // cout << unite(6, 4);
    // for (int i = 0; i <= 5; i++) cout << parent[i] << ' ' << lvl[i] << '\n';
}
/*
5
6 6
1 2 1
2 3 1
3 1 1
4 5 1
5 6 1
6 4 1
6 6
1 2 10
2 3 8
3 1 5
4 5 100
5 6 40
6 4 3
6 15
1 2 4
5 2 8
6 1 7
6 3 10
6 5 1
3 2 8
4 3 4
5 3 6
2 6 6
5 4 5
4 1 3
6 4 5
4 2 1
3 1 7
1 5 5
4 6
2 3 2
1 3 10
1 4 1
3 4 7
2 4 5
1 2 2
4 5
2 1 10
3 1 3
4 2 6
1 4 7
2 3 3

*/