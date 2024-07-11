#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    sort(begin(s), end(s));

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i+1, r = n-1, mid, res = -1;
        int len = s[i].size();
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (s[mid].size() >= len && s[mid].substr(0, len) == s[i]) l = mid + 1, res = mid;
            else r = mid - 1;
        }

        if (res != -1) ans += res - i;
    }

    cout << ans;

}

/*
* Ctrl + Shift + K Delete Line
* Ctrl + / TOGGLE LINE COMMENT
Ctrl + F Find
* Ctrl + H  REPLACE
* shift + alt + f FORMAT CODE DOCUMENT
Ctrl + ]/[ INDENT/OUTDENT LINE
*/