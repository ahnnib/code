#include <iostream>
#include <map>
using namespace std;

#define debug cout << "dfad\n";
#define ll long long

signed main()
{
    int n, m; cin >> n >> m;
    string s; cin >> s;
    map<char, char> p; // p[ch]: kí tự mới của loại kí tự ch trong xâu s
    for (int ch = 'a'; ch <= 'z'; ch++) p[ch] = ch;

    for (int i = 0; i < m; i++) {
        char u, v;
        cin >> u >> v;
        char u2, v2;
        for (int ch = 'a'; ch <= 'z'; ch++) {
            if (p[ch] == u) u2 = ch;
            if (p[ch] == v) v2 = ch;
        }
        char tmp = p[u2];
        p[u2] = p[v2];
        p[v2] = tmp;
    }
    for (int i = 0; i < n; i++) cout << p[s[i]];
}
/*
6 2
abcdce
c d
d c
*/
