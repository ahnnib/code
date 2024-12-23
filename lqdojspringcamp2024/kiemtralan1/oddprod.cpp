#include <bits/stdc++.h>
using ll = int64_t;
using namespace std;
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
int n, a[N], cnt1[N], cnt2[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        cnt1[i] = cnt1[i-1] + !(a[i] & 1);
        cnt2[i] = cnt2[i-1] + (a[i] < 0);
    }

    int pre0 = 1, pre1 = 0; // pre_r: vi tri i nho nhat sao cho cnt2[i] % 2 = r

    if (a[1] > 0) for (int i = 1; i <= n; i++) if (cnt2[i] % 2 == 0) { pre0 = i; break; }
    // neu nhu khong if a[1] thi pre0 se bi dat o vi tri 2, 3, .. -> sai
    for (int i = 1; i <= n; i++) if (cnt2[i] % 2 == 1) { pre1 = i; break; }

    int res = 0;
    for (int r = 1; r <= n; r++) {
        int l;
        if (cnt2[r] % 2 == 1) l = pre1 + 1;
        else l = pre0;
        if (cnt1[r] - cnt1[l-1] > 0) res = max(res, r - l + 1);
    }

    cout << res;
}