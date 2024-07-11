#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    vector< pair<int, int> > palin;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (i-j > 0 && i+j < n && s[i-j] == s[i+j]) j++;
        while (s[i-j] != s[i+j]) j--;
        while (s[i-j] == '0' && s[i+j] == '0' && i-j < i+j) j--;

        if (2 * j + 1 >= len)
        {
            if (2 * j + 1 != len) palin.clear();
            len = 2 * j + 1;
            palin.push_back({i-j, i+j});
        }

        j = 0;
        while (i-j > 0 && i+j-1 < n && s[i-j] == s[i+j-1]) j++;
        while (s[i-j] != s[i+j-1] && i-j < i+j) j--;
        while (s[i-j] == '0' && s[i+j-1] == '0' && i-j < i+j-1) j--;
        // cout << i << ' ' << j << '\n';

        if (2 * j >= len)
        {
            if (2 * j != len) palin.clear();
            len = 2 * j;
            palin.push_back({i-j, i+j-1});
        }
    }

    string ans;
    for (pair<int, int> it : palin)
    {
        string curr;
        for (int i = it.first; i <= it.second; i++) curr += s[i];
        if (ans < curr) ans = curr;
    }

    cout << ans.size() << '\n' << ans;
    // for (auto i : palin) cout << i.first << ' ' << i.second << '\n';
}
/*
(l + j) - (l - j) + 1
l + j - l + j + 1
2 * j + 1

(l + j - 1) - (l - j) + 1
l + j - 1 - l + j + 1
2 * j
*/