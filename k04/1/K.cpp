#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (mp.count(x - a)) {
            cout << mp[x - a] + 1 << ' ' << i + 1;
            return 0;
        }
        mp[a] = i;
    }
    cout << "IMPOSSIBLE";
}