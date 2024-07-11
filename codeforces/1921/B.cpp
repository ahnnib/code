#include <iostream>
using namespace std;

int abs(int x) { return (x < 0 ? -x : x); }

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n; string s, f;
        cin >> n >> s >> f;

        int ans = 0;

        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] > f[i]) t1++;
            if (s[i] < f[i]) t2++;
        }
        int dif = abs(t1 - t2);
        int so_cap = max(t1, t2) - dif;
        cout << so_cap /* swap */ + dif /* add/retire */ << '\n';
    }
}
/*

10011
11101
s -> f
1. đổi chỗ
2. thêm
3. bớt
6

5
10010
00001
2

1
1
1
0

3
000
111
3

4
0101
1010
2

3
100
101
1

8
10011001
11111110
4
*/