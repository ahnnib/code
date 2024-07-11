#include <iostream>
using namespace std;

int p[200001];

void query() {
    int l, r; cin >> l >> r;
    l--, r--;
    if (l > p[r]) cout << "-1 -1\n";
    else cout << p[r] + 1 << ' ' << r + 1 << '\n';
}
void solve() {
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    // p[i]: nearest position to the left j so that a[j] != a[i]
    p[0] = -1; for (int i = 0; i < n; i++) p[i] = (a[i] != a[i-1] ? i-1 : p[i-1]);

    int q; cin >> q; while (q--) query();
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    cerr << "--------------------------------------------------------OUTPUT--------------------------------------------------------\n";
    int t; cin >> t; while (t--) { solve(); cout << '\n'; }
}
/*
5
5
1 1 2 1 1
3
1 5
1 2
1 3
6
30 20 20 10 10 20
5
1 2
2 3
2 4
2 6
3 5
4
5 2 3 4
4
1 2
1 4
2 3
2 4
5
1 4 3 2 4
5
1 5
2 4
3 4
3 5
4 5
5
2 3 1 4 2
7
1 2
1 4
1 5
2 4
2 5
3 5
4 5
*/