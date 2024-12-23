#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    string s; cin >> s;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'p') {
            cout << 'q';
        }
        else if (s[i] == 'q') {
            cout << 'p';
        }
        else {
            cout << 'w';
        }
    }

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}