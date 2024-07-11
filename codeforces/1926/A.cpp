#include <iostream>
using namespace std;

void solve() {
    string s; cin >> s;
    int cnt = 0;
    for (char i : s) {
        if (i == 'A') cnt++;
        if (i == 'B') cnt--;
    }
    cout << (cnt >= 0 ? 'A' : 'B');

    cout << '\n';
}

int main()
{
    int t; cin >> t; while (t--) solve();
}