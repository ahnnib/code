#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    freopen("bai1.gravity.inp", "r", stdin);
    freopen("bai1.gravity.out", "w", stdout);

    int n; cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    for (long long i : a) cout << i << ' ';
}