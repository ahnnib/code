#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> str;
    while (n --> 0)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            while (s[i+1] == c) s.erase(i, 1);
        }

        str.insert(s);
    }
    cout << str.size() << '\n';
}