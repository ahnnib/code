#include <iostream>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    int s[n+2][m+2] = {};
    while (q --> 0)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        s[a][b]++;
        s[c+1][b]--;
        s[a][d+1]--;
        s[c+1][d+1]++;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << s[i][j] << ' ';
        cout << '\n';
    }
}
