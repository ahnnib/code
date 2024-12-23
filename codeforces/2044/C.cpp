#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m, a, b, c;
void sol() {
    cin >> m >> a >> b >> c;

    int slots = m + m;
    slots -= min(a, m);
    slots -= min(b, m);
    if (slots == 0) {
        cout << m + m << '\n';
        return;
    }
    slots -= min(c, slots);
    cout << m + m - slots << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}