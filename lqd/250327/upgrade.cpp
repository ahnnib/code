#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int INF = 1e15;
const int N = 1e5 + 5;

int n, m;
int d1[N], dn[N], cnt1[N], cntn[N];
vector <pii> G[N];
pair <int,pii> op[2 * N];
void dijkstra(int s, int* cnt, int* d) {
    for (int i = 1; i <= n; i++) d[i] = INF;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[s] = 0;
    cnt[s] = 1;
    q.push({0,s});
    while (!q.empty()) {
        pii top = q.top();
        q.pop();
        int u = top.se, kc = top.fi;
        if (d[u] < kc) continue;
        for (auto x : G[u])
        {
            int v = x.fi, w = x.se;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u];
                q.push({d[v],v});
            } else if (d[v] == d[u] + w) cnt[v] += cnt[u];
        }
    }
}


signed main() {
    freopen("upgrade.inp", "r", stdin);
    freopen("upgrade.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, t; cin >> u >> v >> t;
        G[u].emplace_back(v,t);
        G[v].emplace_back(u,t);
        op[i] = {u,{v,t}};
    }

    dijkstra(1, cnt1, d1);
    dijkstra(n, cntn, dn);

    set<pii> br;
    for (int i = 1; i <= m; i++)
    {
        int u = op[i].fi, v = op[i].se.fi, w = op[i].se.se;
        if (d1[u] + dn[v] + w == d1[n] || d1[v] + dn[u] + w == d1[n])
        {
            if (cnt1[u] == cnt1[v] && cntn[u] == cntn[v]) br.insert({min(u,v), max(u,v)});
        }
    }
    cout << br.size();
}
