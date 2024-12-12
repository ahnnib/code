#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n;
void sol() {
    cin >> n;
    int op = 1; ll t = 1;
    while (t < n) {
        t = (t + 1) * 2;
        op++;
    }
    cout << op << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}