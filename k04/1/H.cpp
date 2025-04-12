#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multiset<int> s;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        s.insert(h);
    }
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        auto idx = s.upper_bound(t);
        if (idx == s.begin()) cout << -1;
        else {
            advance(idx, -1);
            cout << *idx;
            s.erase(idx);
        }
        cout << '\n';
    }
}