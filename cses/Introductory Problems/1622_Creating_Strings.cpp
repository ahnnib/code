#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<string> str;
    string old = s;
    next_permutation(s.begin(), s.end());

    while (s != old)
    {
        str.push_back(s);
        next_permutation(s.begin(), s.end());
        // cout << s << '\n';
    }

    str.push_back(s); sort(str.begin(), str.end());
    cout << str.size() << '\n';
    for (string i : str) cout << i << '\n';
}