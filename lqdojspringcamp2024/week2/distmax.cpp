#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";
#define x first
#define y second

const int N = 2e5;

int n; pair<int, int> p[N];
int mi[N], ma[N];

bool check(int k) { // ton tai cap diem co khoang cach >= k
    for (int i = 0; i < n; i++) {
        int l = 0, r = i-1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (p[mid].x + k <= p[i].x) l = mid + 1;
            else r = mid - 1;
        }
        if (0 <= r) if (mi[r] + k <= p[i].y || p[i].y + k <= ma[r]) return true;
    }
    return false;
}
/*
bool check2(int k) { // 2-pointer, 400% faster
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (j < i && p[j].x + k <= p[i].x) {
            while (j < i && p[j].x + k <= p[i].x) j++;
            j--;
        }
        // cout << i << ' ' << j << '\n';
        if (0 <= j && (mi[j] + k <= p[i].y || p[i].y + k <= ma[j])) return true;
    }
    return false;
}
*/
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n; for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    sort(p, p + n);

    mi[0] = ma[0] = p[0].y; for (int i = 1; i < n; i++) mi[i] = min(mi[i-1], p[i].y), ma[i] = max(ma[i-1], p[i].y);

    int l = 0, r = 1e9, k;
    while (l <= r) {
        k = (l + r) >> 1;
        if (check(k)) l = k + 1;
        else r = k - 1;
        // cout << k << '\n';
    }

    cout << r;
}
