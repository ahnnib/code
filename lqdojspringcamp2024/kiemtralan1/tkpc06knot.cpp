#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";
#define x first
#define l second
int n;
pair<int, int> s[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i].x >> s[i].l;

    sort(s, s + n);

    auto kt = [&](int d) -> bool {
        int point = s[0].x;
        for (int i = 1; i < n; i++) {
            point = max(point + d, s[i].x);
            if (point > s[i].x + s[i].l) return false;
        }
        return true;
    };

    int l = 1, r = 2e9, mid;
    while (l <= r) {
        mid = l + (r - l >> 1);
        if (kt(mid)) {
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << r;
}