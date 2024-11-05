#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

char c[1001][1001];

void sol() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    int cnt = 0;

    auto traverse = [&](int t) {
        string tmp;
        for (int j = t; j < m - t + 1; j++) {
            tmp += c[t][j];
        }
        for (int i = t; i < n - t + 1; i++) {
            tmp += c[i][m - t + 1];
        }
        for (int j = m - t + 1; j > t; j--) {
            tmp += c[n - t + 1][j];
        }
        for (int i = n - t + 1; i > t; i--) {
            tmp += c[i][t];
        }
        tmp += tmp.substr(0, 3);
        return tmp;

    };
    for (int i = 1; i <= min(n/2, m/2); i++) {
        string tmp = traverse(i);
        for (int j = 0; j + 3 < tmp.size(); j++) {
            if (tmp.substr(j, 4) == "1543") cnt++;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}