#include <iostream>
#include <vector>
using namespace std;

const int N = 5e5 + 1;
int n, m;
vector<int> dsk[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        dsk[u].push_back(v); dsk[v].push_back(u);
    }

    vector<int> le;
    for (int i = 1; i <= n; i++)
    {
        if (dsk[i].size() == 1) le.push_back(i);
    }

    int nd = le.size();

    if (nd % 2)
    {
        cout << nd / 2 + 1 << '\n';
        for (int i = 0; i < nd - 2; i += 2)
            cout << le[i] << ' ' << le[i+1] << '\n';
        cout << le[nd-1] << ' ' << 1;
    }
    else
    {
        cout << nd / 2 << '\n';
        for (int i = 0; i <= nd - 2; i += 2)
            cout <<  le[i] << ' ' << le[i+1] << '\n';
    }
}
/*
6 5
1 2
2 3
2 4
5 4
6 4

*/