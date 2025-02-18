#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, r[1001]; bool vis[1001];
ll res = 1;

ll dfs(int u) {
    ll len = 0;
    while (!vis[u]) {
        vis[u] = true;
        u = r[u];
        len++;
    }
    return len;
}

void ac() {
    for (int i = 1; i <= n; i++) {
        if (!vis[r[i]]) {
            // res = lcm(res, dfs(r[i]));
            res = max(res, dfs(r[i]));
        }
    }
    cout << res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];

    ac();
}