#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int h; cin >> h;
        auto idx = s.upper_bound(h);
        if (idx != s.end()) {
            s.erase(idx);
        }
        else {
        }
        s.insert(h);
    }
    cout << s.size();
}