#include <iostream>

int main()
{
    int n; std::string s;
    std::cin >> n >> s;

    int d[68] = {};
    for (char i : s) d[i]++;


    int m = std::min(d['A'], d['B']);
    d['A'] -= m, d['B'] -= m;
        m = std::min(d['B'], d['C']);
    d['B'] -= m, d['C'] -= m;

    std::cout << (d['C'] == 0 ? "YES" : "NO");
}
