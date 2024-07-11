#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("palin.inp", "r", stdin);
    freopen("palin.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        bool c = 1;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1]) { c = 0; break; }
        }

        if (c) cout << "YES\n";
        else cout << "NO\n";
    }
}