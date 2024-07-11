#include <iostream>
using namespace std;

bool mark[21];
int n;
void dq(int pos) {
    for (int i : {0, 1}) {
        mark[pos] = i;
        if (pos == n) {
            for (int j = 1; j <= n; j++) cout << mark[j];
            cout << '\n';
        }
        else {
            dq(pos + 1);
        }
    }
}

int main() {
    cin >> n;

    dq(1);

    // for (int i = 0; i < 1<<n; i++) {
    //     for (int j = n-1; j >= 0; j--) {
    //         cout << ((i & (1<<j)) ? 1 : 0);
    //     }
    //     cout << '\n';
    // }
}