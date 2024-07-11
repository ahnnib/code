#include <iostream>
#include <map>
using namespace std;

int main()
{
    int k; std::string s;
    std::cin >> k >> s;

    int n = s.size();
    s += s;
    std::map<std::string, int> map;
    for (int i = 0; i < n; i++)
        map[s.substr(i, n)]++;


    int j = 0;
    for (auto i : map)
    {
        j++;
        if (j == k) return std::cout << i.first, 0;
    }

    std::cout << -1;
}