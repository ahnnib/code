#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void sol() {
    int x, y, k; cin >> x >> y >> k;
    int moves_x = (x + k - 1) / k;
    int moves_y = (y + k - 1) / k;
    cout << max(moves_x * 2 - 1, moves_y * 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}