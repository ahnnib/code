#include <iostream>
#include <algorithm>
using namespace std;

bool mark[(int)1e7 + 1];
int d[(int)1e7 + 1];

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("count.inp", "r", stdin);
    freopen("count.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[n];

    int Q = 0, P = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        d[a[i]]++; P = max(P, d[a[i]]);
        if (!mark[a[i]]) mark[a[i]] = 1, Q++;
    }

    // sort(d, d + (int)1e7, greater<int>());

    cout << Q << '\n' << P; //
}