#include <iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    int d[123] = {};
    for (char i : s) d[i]++;
    for (int i = 'a'; i <= 'z'; i++) {
        if (d[i] % 2) return cout << "No", 0;
    }
    cout << "Yes";
}