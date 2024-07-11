#include <iostream>
using namespace std;

const int MAX = 1e5 + 1;

int dsu[MAX], sz[MAX];
int n;

void init(){
    for (int i = 1; i <= MAX; i++)
        dsu[i] = i, sz[i] = 1;
}

int find(int u){
    if (dsu[u] == u) return u;
    return dsu[u] = find(dsu[u]);
}

bool check(int u, int v){
    return find(u) == find(v);
}

bool unite(int u, int v){
    // true nếu ghép được, v nếu không ghép được
    u = find(u), v = find(v);
    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);
    dsu[v] = u; sz[u] += sz[v];
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init();

    int n, m;
    cin >> n >> m;

    int cnt = n, maxsz = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        if (unite(u, v)) cnt--;
        maxsz = max(maxsz, sz[find(u)]);

        cout << cnt << ' ' << maxsz << '\n';
    }
}