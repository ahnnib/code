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

    int h[n+1] = {}; // number of consecutive 1s counting from row i as base
    ll res = 0;

    for (int i = 0; i < m; i++) {
        // calculate number of consecutive 1s
        for (int j = 0; j < n; j++) {
            h[j] = grid[i][j] ? h[j] + 1 : 0;
        }
        /*
        When we traverse the array by finding the next greater element, we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves
        So we can find the area of the rectangle by using h[i] * (right smaller - left smaller - 1)
        */
        stack<int> st;
        for (int j = 0; j <= n; j++) {
            while (!st.empty() && (j == n || h[st.top()] >= h[j])) {
                ll height = h[st.top()];
                st.pop();
                ll width = st.empty() ? j : j - st.top() - 1;
                res = max(res, height * width);
            }
            st.push(j);
        }
    }

    cout << res;
}