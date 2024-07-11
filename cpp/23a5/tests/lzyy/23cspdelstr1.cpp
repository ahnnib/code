#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("delstr.inp", "r", stdin);
    freopen("delstr.out", "w", stdout);
    #endif

    int k; string s;
    cin >> k >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        while (s[j] == s[i] && j < s.size())
        {
            j++;
            if (j - i + 1 > k) break;
        } j--;
        if (j - i + 1 >= k) s.erase(i, k), i = -1;
    }

    if (!s.empty()) cout << s;
    else cout << 0;
}