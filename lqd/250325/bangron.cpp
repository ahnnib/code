#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    freopen("bangron.inp", "r", stdin);
    freopen("bangron.out", "w", stdout);
    string s; cin >> s;

    int n = s.size();
    s = ' ' + s;

    vector< vector<int> > cnt(3, vector<int> (n+1));
    for (int i = 1; i <= n; i++) {
        cnt[0][i] = cnt[0][i-1] + (s[i] == 'O');
        cnt[1][i] = cnt[1x][i-1] + (s[i] == 'L');
        cnt[2][i] = cnt[2][i-1] + (s[i] == 'P');
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            if (cnt[0][j] - cnt[0][i-1] >= 3 ||
                cnt[1][j] - cnt[1][i-1] >= 3 ||
                cnt[2][j] - cnt[2][i-1] >= 3) {
                res += n - j + 1;
                break;
            }
        }
    }
    cout << res;
}