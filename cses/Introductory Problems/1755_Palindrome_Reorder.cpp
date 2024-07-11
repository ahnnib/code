#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    int d['Z' + 1] = {};
    for (char i : s) d[i]++;

    string ans;
    int cntodd = 0;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (d[i] % 2)
        {
            cntodd++;
            if (!(n % 2) || cntodd >= 2) return cout << "NO SOLUTION", 0;
        }

        else for (int j = 0; j < d[i] / 2; j++)
        {
            ans += (char) i;
        }

    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    // cout << d['D'] << '\n';
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (d[i] % 2) while (d[i]--) cout << (char) i;
    }
    cout << ans << '\n';
}
/*
Input:
AAAACACBA

6 1 2

Output:
AACABACAA

input
AADDDCC

2 0 2 3
ans = "AC"


correct output
ACDDDCA

user output
ACDDDDDCA
*/