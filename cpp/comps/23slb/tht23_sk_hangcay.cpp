#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    while (q--)
    {
        int l, r;
        cin >> l >> r;

    }
}
/*
5
1 2 3 4 5
2 5 7
1 4 5
1 3 3
3 5 3
4 5 1
*/