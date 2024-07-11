#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;

    int s = 0;
    while (n.size() > 1)
    {
        for (char i : n) s += i - 48;
        n = to_string(s);
        s = 0;
    }

    cout << n;
}