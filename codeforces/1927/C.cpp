#include <iostream>
using namespace std;

const int N = 1000001;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        int n, m, k, x; cin >> n >> m >> k;

        bool d1[N] = {}, d2[N] = {};
        bool check = 1; int t1 = 0, t2 = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x <= k) {
                t1 += !d1[x];
                d1[x] = 1;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (x <= k) {
                t2 += !d2[x];
                d2[x] = 1;
            }
        }

        for (int i = 1; i <= k; i++) {
            if (d1[i] == 0 && d2[i] == 0) { check = 0; break; }
        }

        // cout << check << ' ' << t1 << ' ' << t2 << '\n';
        cout << ((check && t1 >= k>>1 && t2 >= k>>1) ? "YES\n" : "NO\n");
    }

}
/*
6
6 5 6
2 3 8 5 6 5
1 3 4 10 5
6 5 6
2 3 4 5 6 5
1 3 8 10 3
3 3 4
1 3 5
2 4 6
2 5 4
1 4
7 3 4 4 2
1 4 2
2
6 4 4 2
1 5 2
3
2 2 1 4 3

*/