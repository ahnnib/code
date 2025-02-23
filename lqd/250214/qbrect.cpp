#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m, n; bool grid[1001][1001] = {};

int main() {

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    int h[n] = {}; // number of consecutive 1s counting from row i as base
    ll res = 0;

    for (int i = 0; i < m; i++) {


        // calculate number of consecutive 1s
        for (int j = 0; j < n; j++) {
            h[j] = grid[i][j] ? h[j] + 1 : 0;
        }
        // for (int j = 0; j < n; j++) {
        //     cout << h[j] << ' ';
        // } cout << '\n';


        stack<int> st;
        for (int j = 0; j < n; j++) {  // Include `n` for final cleanup
            while (!st.empty() && h[st.top()] >= h[j]) {
                st.pop();
            }
            res = max(res, 1ll * h[j] * (j - st.top()));
            st.push(j);
        }
    }

    cout << res;
}