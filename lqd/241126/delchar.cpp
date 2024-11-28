#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

string s;
void sol() {
    cin >> s;
    s = '#' + s + '#';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (s[i-1] == '1') s.erase(i, 1), cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}