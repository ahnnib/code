#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int fjfj = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        fjfj = max(fjfj, w);
    }
    cout << fjfj;
}