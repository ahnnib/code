#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int dif(int a, int b) { return abs(a - b); }

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m; int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        sort(a, a + n); sort(b, b + m, greater<int>());

        int c[n]; long long D = 0;
        for (int i = 0; i < n; i++) // first k numbers of a go with n-k numbers from b
        {
            c[i] = b[m-n+i];
            D += abs(a[i] - c[i]);
        }
        long long res = 0;
        for (int k = 0; k < n; k++)
        {
            res = max(res, D);
            D -= abs(a[k] - c[k]);
            c[k] = b[k];
            D += abs(a[k] - c[k]);
        }
        res = max(res, D);
        cout << res << '\n';
    }
}
/*
4 6
6 1 2 4
3 5 1 7 2 3
1 2 4 6
7 5 3 3 2 1
3 4
1 1 1
1 1 1 1
5 5
1 2 3 4 5
1 2 3 4 5
2 6
5 8
8 7 5 8 2 10
2 2
4 1
9 6
4 6
8 10 6 4
3 10 6 1 8 9
3 5
6 5 2
1 7 9 7 2
5 5
9 10 6 3 7
5 9 2 3 9
1 6
3
2 7 10 1 1 5

*/