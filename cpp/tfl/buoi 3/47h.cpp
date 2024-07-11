#include <iostream>
#include <math.h>
using namespace std;

long double dist(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1,
        dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    long long n, m, u, v, r; cin >> n >> m >> u >> v >> r;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (dist(u, v, i, j) <= r) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}