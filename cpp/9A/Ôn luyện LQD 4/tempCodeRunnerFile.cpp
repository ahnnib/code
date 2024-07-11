#include <unordered_map>
#include <map>
#include <iostream>

typedef fi first;
typedef se second;

int main()
{
    std::unordered_map<int ,int> u;
    std::map<int ,int> v;

    u[2] = 3;
    u[1] = 2;

    v[2] = 5;
    v[1] = 3;

    for (auto i : u) std::cout << i.fi << ' ' << i.se << '\n';
    std::cout << '\n';
    for (auto i : v) std::cout << i.fi << ' ' << i.se << '\n';
}