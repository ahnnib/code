#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define int long long

int d[100001] = {};
signed main()
{
    int n, k;
    cin >> n >> k;
    int a[k];
    for (int i = 0; i < k; i++) cin >> a[i];

    sort(a, a + k, greater<int>());

    set<int> s;
    s.insert(a[0]);
    int i, pos;
    for (i = 0; i < k; i++)
    {
        if (s.size() == n) break;
        if (a[i] != a[i-1]) s.insert(a[i]), pos = i;
    }

    // cout << pos << '\n';
    int sum = 0;
    for (int i : s) sum += i;

    cout << sum;
}
/*
8 14
1 7 9 6 4 3 12 6 7 3 4 1 1 3
1 1 1 3 3 3 4 4 6 6 7 7 9 12
12 9 7 7 6 6 4 4 3 3 3 1 1 1


12 9 7 6 4 3 1
42
*/
