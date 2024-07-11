#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

const int MAX = 2e5 + 7;
int n, q, a[MAX];

int min_range(int l, int r)
{
    // base case
    if (l == r) return a[l];

    int mid = (l + r) >> 1;
    return min(min_range(l, mid), min_range(mid+1, r));
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    while (q--) {
        int a, b; cin >> a >> b;

        cout << min_range(a, b) << '\n';
    }
}