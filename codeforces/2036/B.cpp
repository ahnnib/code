#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    vector <pair<int, int> > bottles;
    for (int i = 0; i < k; i++) {
        int b, c; cin >> b >> c;
        mp[b] += c;
    }

    for (auto i : mp) bottles.push_back(make_pair(i.second, i.first));

    sort(bottles.begin(), bottles.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    });

    // for (auto i : bottles) {
    //     cout << i.first << ' ' << i.second << '\n';
    // }

    int cnt = 0, res = 0;
    map<int, bool> mark;
    for (auto i : bottles) {
        if (!mark[i.second]) cnt++;
        mark[i.second] = 1;
        if (cnt <= n) res += i.first;
        else break;
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}