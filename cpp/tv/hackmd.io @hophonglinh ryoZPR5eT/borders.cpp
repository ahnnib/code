#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int nd = s.size();
    for (int i = 1; i < nd; i++)
    {
        if (s.substr(0, i) == s.substr(nd - i, i)) cout << i << ' ';
    }
}