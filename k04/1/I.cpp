#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int q, x;
    while (cin >> q && q != 0) {
        if (q == 1) {
            cin >> x;
            s.insert(x);
        }
        else if (q == 2) {
            cin >> x;
            s.erase(x);
        }
        else if (q == 3) {
            if (s.empty()) cout << "empty\n";
            else cout << *s.begin() << '\n';
        }
        else if (q == 4) {
            if (s.empty()) cout << "empty\n";
            else cout << *prev(s.end()) << '\n';
        }
        else {
            cin >> x;
            if (s.empty()) cout << "empty\n";

            else if (q == 5) {
                auto it = s.upper_bound(x);
                if (it == s.end()) cout << "no\n";
                else cout << *it << '\n';
            }
            else if (q == 6) {
                auto it = s.lower_bound(x);
                if (it == s.end()) cout << "no\n";
                else cout << *it << '\n';
            }
            else if (q == 7) {
                auto it = s.lower_bound(x);
                if (it == s.begin()) cout << "no\n";
                else {
                    advance(it, -1);
                    cout << *it << '\n';
                }
            }
            else if (q == 8) {
                auto it = s.upper_bound(x);
                if (it == s.begin()) cout << "no\n";
                else {
                    advance(it, -1);
                    cout << *it << '\n';
                }
            }
        }
    }
}