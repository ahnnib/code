#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    char t; int v;
    while (cin >> t) {
        if (t == '+') {
            cin >> v;
            if (s.size() < 15000) s.insert(v);
        }
        else if  (t == '-') {
            if (!s.empty()) s.erase(prev(s.end()));
        }

    }
    cout << s.size() << '\n';
    for (multiset<int>::reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
        cout << *it << '\n';
    }
}