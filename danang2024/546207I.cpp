#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int m, n, a[100001]; ll s[100001];
bool kt(int L) {
    for (int i = L; i <= n; i++) {
        if (s[i] - s[i - L] < m) return 0;
    }
    return 1;
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    int l = 1, r = n, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (kt(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l;
}
