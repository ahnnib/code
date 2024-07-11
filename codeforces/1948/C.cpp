/*
#include <iostream>
using namespace std;

void solve() {
    int n; string s1, s2; cin >> n >> s1 >> s2;

    bool c = 1;
    for (int i = 2; i <= n-1 && c; i += 2) {
        if (s2[i] == '<' && (s1[i-1] == '<' || s1[i+1] == '<')) c = 0;
    }

    cout << (c ? "YES" : "NO");

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
int adr(int r, int c) { return c + n * (r-1); }
bool check(int r, int c) {
    if (r == 1) return c & 1;
    return !(c & 1);
}

vector<int> G[400014];
vector<bool> vis(400014);

void dfs(int u) {
    vis[u] = 1;
    for (int v : G[u]) if (!vis[v]) dfs(v);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) G[i].clear();
    vis.assign(2 * n + 1, 0);
    for (int r : {1, 2}) {
        for (int c = 1; c <= n; c++) {
            char ch; cin >> ch;
            if (check(r, c)) { // connect to adj
                // cout << "even cell ";
                for (int i : {-1, 0, 1}) for (int j : {-1, 0, 1}) {
                    if (i == j || i == -j) continue;
                    if (r + i < 1 || r + i > 2) continue;
                    if (c + j < 1 || c + j > n) continue;
                    G[adr(r, c)].push_back(adr(r+i, c+j));
                    // cout << adr(r, c) << ' ' << adr(r+i, c+j) << '\n';
                }
            }
            else { // connect to next
                // cout << "odd cell ";
                int cc = c;
                if (ch == '>') cc++; else cc--;
                if (cc < 1 || cc > n) continue;
                G[adr(r, c)].push_back(adr(r, cc));
                // cout << adr(r, c) << ' ' << adr(r, cc) << '\n';
            }
        }
    }
    G[2*n].clear();

    // for (int i = 1; i <= (n<<1); i++) {
    //     if (!G[i].empty()) {
    //         cout << i << ": ";
    //         for (auto j : G[i]) cout << j << ' ';
    //         cout << '\n';
    //     }
    // }

    dfs(1);
    // for (int i = 1; i <= 2 * n; i++) cout << vis[i] << ' ';
    if (vis[2*n]) cout << "YES";
    else cout << "NO";

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}
/*
*/