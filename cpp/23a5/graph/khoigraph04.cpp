#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    cout << 6 * (n - 1) * (n - 1) - ((n - 1) * (n - 2) * 2);
    // 6: number of edges in a 1x1 "square"
    // 2(n-1)(n-2): number of double-counted edges
}
// undirected n*n node graph. count number of edges
/*
._.
|x|
._.
*/