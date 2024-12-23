#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int n, x;
void sol() {
    cin >> n;
    int b[n] = {};
    vector<bool> mark(n+1, false);
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!mark[x]) {
            b[i] = x;
            mark[x] = true;
        }
    }

    queue<int> rand;
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) rand.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (!b[i]) {
            b[i] = rand.front();
            rand.pop();
        }
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}