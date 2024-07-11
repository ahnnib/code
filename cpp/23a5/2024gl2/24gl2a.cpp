#include <iostream>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;

    if (r - l + 1 <= 3) {
        if (l % 2 && r % 2 && l != r) cout << l << ' ' << r;
        else cout << -1;
        return 0;
    }

    if (r % 2 == 0) r--;
    cout << r - 2 << ' ' << r << '\n';
}