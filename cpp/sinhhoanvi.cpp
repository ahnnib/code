#include <iostream>
using namespace std;

int n;
bool mark[21];
void dq(int pos, int num) {
    for (int i = 1; i <= n; i++) {
        if (mark[i]) continue;
        if (pos == n) cout << num << i << '\n';
        mark[i] = 1;
        dq(pos + 1, num * 10 + i);
        mark[i] = 0;
    }
}
int main() {
    cin >> n;
    dq(1, 0);
}
/*

*/