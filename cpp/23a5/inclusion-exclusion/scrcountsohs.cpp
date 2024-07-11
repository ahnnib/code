#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int u[8];
        for (int i = 1; i <= 7; i++) cin >> u[i];

        int ans = u[1] + u[2] + u[3] - u[4] - u[5] - u[6] + u[7];

        bool tm = 1;
        for (int i = 1; i <= 7; i++) if (ans < u[i]) tm = 0;
        for (int i = 1; i <= 6; i++) if (u[7] > u[i]) tm = 0;
        if (u[5] > u[1] || u[5] > u[2] ||
            u[4] > u[2] || u[4] > u[3] ||
            u[6] > u[1] || u[6] > u[3])
            tm = 0;

        cout << (tm ? ans : -1) << '\n';
    }
}
