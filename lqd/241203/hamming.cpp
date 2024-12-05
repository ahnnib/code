#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n, m, k; cin >> n >> m >> k;

    string N, M;
    cin >> N;

    N = N + N.substr(0, m);
    n = N.size();

    int res = 1e9;
    for (int i = 0; i < k; i++) {
        cin >> M;

        for (int k = 0; k + m < n; k++) {
            int hamming = 0;
            for (int j = k; j < k + m; j++) {
                hamming += N[j] != M[j - k];
            }

            res = min(res, hamming);
            // cout << k << ':' << hamming << ' ';
        }
        // cout << '\n';
    }

    cout << res;
}