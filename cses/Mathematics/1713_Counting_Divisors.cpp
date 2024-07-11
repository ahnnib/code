#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n --> 0)
    {
        int x;
        cin >> x;

        int ans = 0;
        for (int i = 1; i * i <= x; i++)
            if (x % i == 0) ans += 2 - (i == x / i);

        cout << ans << '\n';
    }
}