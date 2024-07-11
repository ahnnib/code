#include <iostream>
#include <map>
using namespace std;

#define int long long

/*
2 5 10 4 4 9 6 7 8

0 2 10 4 6 8
0 5 4 9 7

0 2 12 16 22 30
0 5 9 18 25

*/
void solve() {
    int n; cin >> n; int a[n+1] = {}, s[n+1] = {}; for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) s[i] = s[i-1] + a[i];
        else s[i] = s[i-1] - a[i];
    }

    map<int, bool> mp; mp[0] = 1;
    bool c = 0;
    for (int i = 1; i <= n; i++) {
        if (!mp[s[i]]) mp[s[i]] = 1;
        else { c = 1; break; }
    }

    cout << (c ? "YES" : "NO");

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}