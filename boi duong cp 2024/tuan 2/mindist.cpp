#include <iostream>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define pii pair<int, int>

int abs(int x) { return x < 0 ? -x : x; }
int dist(pii A, pii B) {
    int dx = abs(A.x - B.x),
        dy = abs(A.y - B.y);
    return min(dx, dy);
}

int main()
{
    int n; cin >> n;
    pii p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + n);

    int res = 2147483647;
    for (int i = 0; i < n-1; i++) {
        res = min(res, dist(p[i], p[i+1]));
    }

    cout << res;
}