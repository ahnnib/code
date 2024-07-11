#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x, ind[n+1];
    for (int i = 1; i <= n; i++)
        cin >> x,
        ind[x] = i;

    int res = 1;
    for (int i = 1; i < n; i++)
        if (ind[i] > ind[i+1]) res++;

    cout << res << '\n';
}
/*
4 2 1 5 3
3 2 5 1 4
*/