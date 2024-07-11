#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int x = 0, y = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N') y++;
            if (s[i] == 'S') y--;
            if (s[i] == 'E') x++;
            if (s[i] == 'W') x--;
        }
        cout << x << ' ' << y << '\n';
    }
}

