#include <iostream>
using namespace std;
#define ll long long

char grid[8][8];
bool col[8], diag1[15], diag2[15];
ll res = 0;

void dq(int k) {
    if (k == 8) {
        res++;
        return;
    }
    for (int j = 0; j < 8; j++) {
        if (grid[k][j] == '.' && !col[j] && !diag1[k + j] && !diag2[k - j + 7]) {
            col[j] = diag1[k + j] = diag2[k - j + 7] = true;
            dq(k + 1);
            col[j] = diag1[k + j] = diag2[k - j + 7] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
        }
    }

    dq(0);

    cout << res << '\n';
}