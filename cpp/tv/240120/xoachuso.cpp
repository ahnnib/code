#include <iostream>
using namespace std;

int main()
{
    // freopen("xoachuso.inp", "r", stdin);
    // freopen("xoachuso.inp", "r", stdin);

    string s; getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9') s.erase(i, 1), i--;
    }

    cout << s;
}