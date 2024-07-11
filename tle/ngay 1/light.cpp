#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 7;
const int M = 1e7 + 7;
int n, m, a[N], b[N], max_a, max_b;
int d[M] = {};

void sub145() {
    for (int i = 1; i <= n; i++) {
        d[max(a[i] - b[i], 1)]++;
        d[a[i] + b[i] + 1]--;
    }
    for (int i = 1; i < M; i++) d[i] += d[i-1];

    for (int i = 0; i < m; i++) { int p; cin >> p; cout << d[p] << ' '; }
}
void sub2a() {
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        cout << (max_a - max_b <= p && p <= max_a + max_b ? 1 : 0) << ' ';
    }
}
void sub2b() {
    int p; cin >> p;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - b[i] <= p && p <= a[i] + b[i]) cnt++;
    }
    cout << cnt;
}
void sub3() {
    sort(b + 1, b + n + 1);
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        int l = 1, r = n, mid, res;
        while (l <= r) { // dau tien
        // tìm i sao cho 1 + b[i] >= p
            mid = (l + r) >> 1;
            if (1 + b[mid] < p) l = mid + 1;
            else res = mid, r = mid - 1;
        }
        cout << n - res + 1 << ' ';
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("light.inp", "r", stdin);
    freopen("light.out", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], max_a = max(max_a, a[i]);
    for (int i = 1; i <= n; i++) cin >> b[i], max_b = max(max_b, b[i]);

    // if (n <= 5000 && max_a <= 2000 && max_b <= 2000) sub1();
    if (n == 1) sub2a();
    else if (m == 1) sub2b();
    else if (max_a == 1) sub3();
    else sub145();
}
/*
4 3
1 1 2 3
2 3 3 1


3 1 0 -2 -1 -1 0

3 4 4 2 1 0 0
*/