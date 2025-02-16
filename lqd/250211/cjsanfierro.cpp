#include <bits/stdc++.h>
#define task "testing"
#define int long long
using namespace std;

const int N = 1e5;

struct Edge {
    int u, v, l, h;
};

bool cmp(Edge u, Edge v) {
    return u.h > v.h;
}

Edge e[2*N+5];

vector<pair<int, int>> adj[N+5];

int dsu[N+5], dist[N+5], pre[N+5], vis[N+5];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int find(int v) {
    return (dsu[v] < 0 ? v : dsu[v] = find(dsu[v]));
}

void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;

    if (dsu[u] > dsu[v]) swap(u, v);

    dsu[u] += dsu[v], dsu[v] = u;

    return;
}

bool check(int u, int v) {
    return find(u) == find(v);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    int n, m, s, t; cin >> n >> m >> s >> t;

    for (int x = 1; x <= n; x++) dsu[x] = -1;

    for (int x = 1; x <= m; x++) {
        cin >> e[x].u >> e[x].v >> e[x].l >> e[x].h;
    }

    sort(e+1, e+m+1, cmp);

    int mn = 1e18;

    for (int x = 1; x <= m; x++) {
        if (mn != 1e18 && e[x].h != mn) break;

        unite(e[x].u, e[x].v);

        adj[e[x].u].push_back(make_pair(e[x].v, e[x].l));
        adj[e[x].v].push_back(make_pair(e[x].u, e[x].l));

        if (check(s, t)) mn = e[x].h;
    }

    cout << mn << "\n";

    fill(dist+1, dist+n+1, 1e18), dist[s] = 0;

    pq.push(make_pair(dist[s], s));

    while (!pq.empty()) {
        auto [cst, v] = pq.top(); pq.pop();

        if (vis[v]) continue; vis[v] = 1;

        for (auto u : adj[v]) {
            int val = cst+u.second;

            if (dist[u.first] > val) {
                dist[u.first] = val, pre[u.first] = v;

                pq.push(make_pair(val, u.first));
            }
        }
    }

    vector<int> ans = {t};

    while (t != s) {
        ans.push_back(t = pre[t]);
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << " ";
    }

    return cout << "\n", 0;
}