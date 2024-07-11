#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t; while (t--) {
        string s;
        int cnt[123] = {};
        int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int ch = 'a'; ch <= 'z'; ch++) {
                if (a[i] == cnt[ch]) { s.push_back(ch); cnt[ch]++; break; }
            }
        }
        cout << s << '\n';
    }
}
/*
0 0 0 1 0 2 0 3 1 1 4
a     a   a   a     a
  b             b
    c             c
        d   e
abcadaeabca
abcacadabca
*/