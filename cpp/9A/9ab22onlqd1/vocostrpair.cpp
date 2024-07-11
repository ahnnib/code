#include <iostream>

bool nguyenam(std::string s)
{
    for (char i : s)
        if (i != 'A' || i != 'E' || i != 'I' || i != 'O' || i != 'U')
            return 0;
    return 1;
}

bool phuam(std::string s)
{
    return !nguyenam(s);
}

int main()
{
    #define task "vocostrpair"
    #ifndef ONLINE_JUDGE
    #else
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    #endif

    std::cout << nguyenam("A");

}