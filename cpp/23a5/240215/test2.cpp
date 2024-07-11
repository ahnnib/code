#include <iostream>
using namespace std;

bool mark[21];
int n, k;
void check() {
    for (int i = 1; i <= n; i++) cout << mark[i];
    cout << '\n';
}
void sinhnp(int i) {
    if (i == n) { check(); return; }
    for (int j : {0, 1}) {
        sinhnp(i+1);
        mark[i] = j;
    }
}

int main()
{
    cin >> n;
    // sinhnp(1);
    for (int i = 0; i < 1<<n; i++) {
        for (int j = n-1; j >= 0; j--) {
            cout << (i & 1<<j ? 1 : 0);
        }
        cout << '\n';
    }
}