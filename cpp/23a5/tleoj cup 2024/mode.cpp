#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    #ifndef ONLINE_JUDGE
    #else
    freopen("mode.inp", "r", stdin);
    freopen("mode.out", "w", stdout);
    #endif

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        map<int, int> freq;
        for (int i = l; i <= r; i++) freq[i]++;

        int max_mode = freq[a[l]], min_num = a[l];
        for (int i = l; i <= r; i++)
        {
            if (freq[a[i]] > max_mode)
                max_mode = freq[a[i]],
                min_num = a[i];

            else if (freq[a[i]] == max_mode)
            {
                if (a[i] <= min_num)
                {
                    max_mode = freq[a[i]];
                    min_num = a[i];
                }
            }
        }
        cout << min_num << '\n';
    }
}
/*
5 3
1 2 1 2 3
1 5
1: 2, 2: 2, 3: 1

2 5
1: 1, 2: 2, 3: 1

1 3
1: 2, 2: 1
*/