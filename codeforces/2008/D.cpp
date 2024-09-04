#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 2e5 + 1;
int par[N], sz[N], cntblack[N]; bool vis[N];
int n, p[N]; string s;

void init(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
        vis[i] = 0;
        cntblack[i] = 0;
    }
}
int find(int u) {
    return (par[u] == u ? u : (par[u] = find(par[u])));
}
bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;

    if (sz[x] < sz[y]) {
        swap(x, y);
    }
    par[y] = x;
    sz[x] += sz[y];

    return 1;
}
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1; dfs(p[u]); unite(u, p[u]);
}

void solve() {

    cin >> n; for (int i = 1; i <= n; i++) cin >> p[i]; cin >> s; s = ' ' + s;
    init(n);
    for (int i = 1; i <= n; i++) {
        dfs(p[i]);
    }
    for (int i = 1; i <= n; i++) {
        int u = find(p[i]);
        if (s[i] == '0') cntblack[u]++;
        p[i] = u;
    }
    for (int i = 1; i <= n; i++) {
        cout << cntblack[p[i]] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
}