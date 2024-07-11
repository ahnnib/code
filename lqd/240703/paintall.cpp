#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, a, b;
vector<int> G[100001];
vector<bool> vis(100001);
vector<int> res;

void dfs(int u) {
    res.push_back(u);
    vis[u] = 1; for (auto p : G[u]) if (!vis[p]) dfs(p);
}

int main() {
    vector<int> nodes;
    cin >> n; for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (i == a || i == b) nodes.push_back(i); // tu to mau duoc chinh no
        G[a].push_back(i); G[b].push_back(i);
    }

    for (int i : nodes) {
        if (!vis[i]) dfs(i);

        if (count(vis.begin(), vis.end(), 1) == n) {
            for (int j = res.size()-1; j >= 0; j--) {
                cout << res[j] << '\n';
            }
            return 0;
        }
    }

    cout << -1;
}