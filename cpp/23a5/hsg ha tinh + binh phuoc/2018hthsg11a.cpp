#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("fmnum.inp", "r", stdin);
    freopen("fmnum.out", "w", stdout);
    #endif

    int n, s;
    cin >> n >> s;

    string ans;
    int i;
    for (i = 0; i < n; i++)
    {
        if (s > 9) ans += '9', s -= 9;
        else if (s <= 9) break;
    }

    if (i == n-1) ans += char(s + 48), i++;
    else {
    ans += char(s - 1 + 48); i++;
    for (; i < n-1; i++) ans += '0';
    ans += '1';
    }

    for (i = n-1; i >= 0; i--) cout << ans[i];
}
