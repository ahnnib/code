#include <iostream>
using namespace std;

int main()
{
// gray_code(1) -> gray_code(2) -> ... -> gray_code(n)

    short n;
    cin >> n;

    string gray_code[1<<n] = {""};
    gray_code[0] = "0";
    gray_code[1] = "1";

    int ln = 4;
    for (int i = 2; i < 1<<n; i <<= 1)
    {
        // duplicate L1
        for (int j = i; j < ln; j++)
            gray_code[j] = gray_code[ln - j - 1];

        // push 0 to L1
        for (int j = 0; j < ln / 2; j++)
            gray_code[j] += "0";

        // push 1 to L2
        for (int j = ln / 2; j < ln; j++)
            gray_code[j] += "1";

        ln *= 2;
    }

    for (int i = 0; i < 1<<n; i++)
        cout << gray_code[i] << '\n';
}
