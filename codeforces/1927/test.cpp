#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

#define debug cout << "dfad\n";

vector<int> ans, path; bool found = 0;
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
    if (lvl[u] < lvl[v]) swap(u, v);
    parent[v] = u;
    if (lvl[u] == lvl[v]) lvl[u]++;
    return 1;
}

void solve() {
    int n, m; cin >> n >> m;
    vector < pair<int, pair<int, int> > > edge(m); // w, u, v
    for (int i = 0; i < m; i++) {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }

    sort(edge.rbegin(), edge.rend());

    init(n); ans.resize(0); // dsu + dfs

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

    dfs(best_edge.first, -1, adj, best_edge.second); // tìm chu trình

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
}
