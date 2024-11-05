#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    string s; cin >> s;

    int n = s.size();

    map<string, int> cnt;

    for (int i = 0; i < n-3; i++) {
        cnt[s.substr(i, 4)]++;
    }

    int q; cin >> q; while (q--) {

        int x, y; cin >> x >> y;
        x--;
        int L = max(0, x-3), R = min(x+3, n-1);

        for (int i = L; i <= R; i++) {
            cnt[s.substr(i, 4)]--;
        }

        s[x] = y + '0';

        for (int i = L; i <= R; i++) {
            cnt[s.substr(i, 4)]++;
        }


        cout << (cnt["1100"] ? "YES\n" : "NO\n");
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}
/*
1100000

*/