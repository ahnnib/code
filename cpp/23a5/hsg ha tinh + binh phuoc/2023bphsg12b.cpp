#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int nd = s.size();

    int cnt = 0, res = 0;

    for (int i = 0; i < nd; i++)
    {
        if (s[i] == '0') cnt++;
        else cnt = 0;

        res = max(res, cnt);
    }

    cout << res;
}