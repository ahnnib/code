#include <iostream>

using namespace std;

int main()
{
    int s;
    cin >> s;

    bool no = 1;
    for (int r = 1; r < s / 4; r++)
    {
        for (int c = 1; c < s / 2; c++)
        {
            if (r * 4 + c * 2 == s)
            {
                no = 0;
                cout << "X = " << c << ", Y = " << r << ", ";
                cout << c << " * 2 + " << r << " * 4 = " << s << '\n';
                // input = 20: missing combination "X = 2, Y = 4"?
            }
        }
    }
    if (no) cout << "No solution";

    return 0;
}
