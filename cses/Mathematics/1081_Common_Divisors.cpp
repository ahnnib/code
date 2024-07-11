#include <iostream>
#include <math.h>
using namespace std;

int cnt[(int)1e6 + 1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int root = sqrt(x);
        for (int d = 1; d <= root; d++)
        {
            if (x % d == 0)
            {
                cnt[d]++;
                if (d != x / d) cnt[x / d]++;
            }
        }
    }

    for (int i = 1e6; i >= 1; i--)
        if (cnt[i] >= 2) return cout << i, 0;
}