#include <iostream>
using namespace std;

bool palin(string n)
{
    int nd = n.size();
    for (int i = 0; i < n.size() >> 1; i++)
        if (n[i] != n[nd - i - 1]) return 0;
    return 1;
}

int main()
{
    freopen("palind.inp", "r", stdin);
    freopen("palind.out", "w", stdout);

    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cout << palin(to_string(x + y)) << '\n';
    }
}