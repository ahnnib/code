#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 3e5 + 1;
int n, u, v, a[N];
vector<int> G[N];
vector < pair<int, int> > adj(N);

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> u >> v;

        G[u].push_back(v);
        G[v].push_back(u);

        adj.push_back({u, v});
    }


}