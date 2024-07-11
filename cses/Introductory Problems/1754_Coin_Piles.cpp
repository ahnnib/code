#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        // a + b = (2x + y) + (x + 2y) = 3(x + y)
        cout << (((a + b) % 3 == 0) && (2 * min(a, b) >= max(a, b)) ? "YES\n" : "NO\n");
    }
}