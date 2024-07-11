#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int l, r;
    int sz = 0;
    for (int mid = 0; mid < n; mid++)
    {
        int j = 0;
        while (mid - j >= 0 && mid + j < n && s[mid - j] == s[mid + j]) j++;
        j--;

        if (2 * j + 1 > sz) sz = 2 * j + 1, l = mid - j, r = mid + j;

        j = 0;
        while (mid - j >= 0 && mid + j - 1 < n && s[mid - j] == s[mid + j - 1]) j++;
        j--;

        if (2 * j > sz) sz = 2 * j, l = mid - j, r = mid + j - 1;
    }

    for (int i = l; i <= r; i++) cout << s[i];
}