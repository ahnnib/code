#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> s;
    char t; int v;
    while (cin >> t) {
        if (t == '+') {
            cin >> v;
            if (s.size() < 15000) s.insert(v);
        }
        else {
            if (!s.empty()) s.erase(s.end());
        }
    }
    cout << s.size() << '\n';
    for (multiset<int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << '\n';
    }
}