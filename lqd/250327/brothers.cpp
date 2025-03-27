#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INT_MIN -2e9
// Function to calculate the maximum score
int maxScore(const vector<vector<int>>& grid, int N, int M) {
    // dp1[i][j] stores the maximum score for An reaching cell (i, j)
    // dp2[i][j] stores the maximum score for Bình reaching cell (i, j)
    vector<vector<int>> dp1(N, vector<int>(M, INT_MIN));
    vector<vector<int>> dp2(N, vector<int>(M, INT_MIN));

    // Initialize starting point for both players
    dp1[0][0] = grid[0][0];
    dp2[0][0] = grid[0][0];

    // Fill dp1 for An's path
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i > 0) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + grid[i][j]);
            if (j > 0) dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + grid[i][j]);
        }
    }

    // Fill dp2 for Bình's path starting from bottom-right
    dp2[N - 1][M - 1] = grid[N - 1][M - 1];
    for (int i = N - 1; i >= 0; --i) {
        for (int j = M - 1; j >= 0; --j) {
            if (i < N - 1) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j] + grid[i][j]);
            if (j < M - 1) dp2[i][j] = max(dp2[i][j], dp2[i][j + 1] + grid[i][j]);
        }
    }

    // Calculate the maximum combined score at each cell
    int maxTotalScore = INT_MIN;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            maxTotalScore = max(maxTotalScore, dp1[i][j] + dp2[i][j]);
        }
    }

    return maxTotalScore;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << maxScore(grid, N, M) << endl;
    return 0;
}
