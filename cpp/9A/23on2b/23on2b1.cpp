#include <iostream>

bool hoa(char ch)
{
    return ('A' <= ch && ch <= 'Z');
}
bool thuong(char ch)
{
    return ('a' <= ch && ch <= 'z');
}

int main()
{
    std::string s;
    std::cin >> s;

    s = " " + s;
    for (int i = 1; i < s.size(); i++)
    {
        if (i % 2)
        {
            if (hoa(s[i])) return std::cout << "No", 0;
        }
        else
        {
            if (thuong(s[i])) return std::cout << "No", 0;
        }
    }

    std::cout << "Yes";
}