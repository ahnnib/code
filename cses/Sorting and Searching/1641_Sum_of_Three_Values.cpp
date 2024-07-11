#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    // binary search code
    /*
    for (int i = 0; i < n-2; i++)
    {
        for (int k = i+2; k < n; k++)
        {
            int l = i+1, r = k-1, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (a[i].first + a[k].first + a[mid].first < x) l = mid + 1;
                if (a[i].first + a[k].first + a[mid].first > x) r = mid - 1;
                if (a[i].first + a[k].first + a[mid].first == x)
                    return cout << a[i].second+1 << ' ' << a[mid].second+1 << ' ' << a[k].second+1, 0;
                // {
                //     int arr[3] = {a[i].second+1, a[mid].second+1, a[k].second+1};
                //     sort(arr, arr + 3);
                //     cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];
                //     return 0;
                // }
            }
        }
    }
    */

    // 2 pointers code
    for (int i = 0; i < n-2; i++)
    {
        int k = n-1;
        for (int j = i+1; j < n-1; j++)
        {
            while (k > j+1 && a[i].first + a[j].first + a[k].first > x) k--;
            if (a[i].first + a[j].first + a[k].first == x)
                return cout << a[i].second+1 << ' ' << a[j].second+1 << ' ' << a[k].second+1, 0;
        }
    }

    cout << "IMPOSSIBLE";
}
/*
4 8
2 7 5 1
1 2 5 7
4 1 3 2

*/