#include <iostream>
using namespace std;

int main()
{
    string n;
    cin >> n;

    // while (n[0] == '0') n.erase(0, 1);

    int i = 0;
    for (; n[i] > n[i+1] && i < n.size()-1; i++) {}

    // cout << i << '\n';
    n.erase(i, 1);

    while (n[0] == '0') n.erase(0, 1);

    if (n == "") cout << 0;
    cout << n;
}