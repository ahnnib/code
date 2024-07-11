#include <iostream>
using namespace std;

int main()
{
    string t;
    cin >> t;

    string s;

    int d[123] = {};
    for (char i : t) d[i]++;
    for (int i = 'a'; i <= 'z'; i++)
    {
        for (int j = 0; j < d[i] >> 1; j++)
            s = s + char(i);
    }
    cout << s;
}