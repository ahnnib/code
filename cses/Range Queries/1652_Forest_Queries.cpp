#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    char forest[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        cin >> forest[i][j];

    int c[n+1][n+1] = {};
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
            c[i][j] += c[i-1][j] + c[i][j-1] - c[i-1][j-1] + (forest[i][j] == '*');

    for (int _ = 0; _ < q; _++)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << c[x2][y2] - c[x2][y1-1] - c[x1-1][y2] + c[x1-1][y1-1] << '\n';
    }
}
/*
(x1, y1)    (x1, y2)
(x2, y1)    (x2, y2)
*/