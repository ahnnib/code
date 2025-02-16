#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {

    int m, n; cin >> m >> n;
    bool grid[m][n] = {};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }


    int h[n] = {}; // number of consecutive 1s counting from row i as base

    for (int i = 0; i < m; i++) {


        // calculate number of consecutive 1s
        for (int j = 0; j < n; j++) {
            h[j] = grid[i][j] ? h[j] + 1 : 0;
        }

        // calculate min/max
        stack<int> st;

        int L[n] = {}, R[n] = {};
        for (int i = 0)\


    }
}