#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("delnum.inp", "r", stdin);
    freopen("delnum.out", "w", stdout);
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) if (!('0' <= s[i] && s[i] <= '9')) cout << s[i];
}