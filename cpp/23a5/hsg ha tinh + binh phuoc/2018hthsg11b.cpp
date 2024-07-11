#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("biop.inp", "r", stdin);
    freopen("biop.out", "w", stdout);
    #endif

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++)
    {
        int x = lower_bound(b.begin(), b.end(), a[i]) - b.begin(),
            y = n - (upper_bound(b.begin(), b.end(), a[i]) - b.begin());
        cout << x << ' ' << y << '\n';
    }
}
/*
với mỗi a[i]
in ra số số < a[i]
và số số > a[i]
6
1 3 2 3 6 4
1 2 3 3 4 6
*/