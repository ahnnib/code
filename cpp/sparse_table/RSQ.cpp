#include <iostream>
using namespace std;

const int N = 2e5 + 7;
const int LG = 17;

int n, q, a[N];

long long st[LG + 1][N];
void pp() {
    for (int i = 1; i <= n; i++) st[0][i] = a[i];
    for (int j = 1; j <= LG; j++) {
        for (int i = 1; i + (1<<j) - 1 <= n; i++) {
            st[j][i] = st[j-1][i] + st[j-1][i + (1<<(j-1))];
        }
    }
}
long long query(int l, int r) {
    int k = r - l + 1;
    long long res = 0;
    for (int j = 0; 1<<j <= k; j++) { // for qua từng bit
        if ((k>>j) & 1) {
            res += st[j][l];
            l += 1<<j;
        }
    }
    return res;
}
long long query2(int l, int r) {
    int k = __lg(r - l + 1);
    return st[k][l] + st[k][r - (1<<k) + 1];
}

int main()
{
    cin >> n >> q; for (int i = 1; i <= n; i++) cin >> a[i];

    pp();

    while (q--) {
        int l, r; cin >> l >> r;
        cout << query2(l, r) << '\n';
    }
}