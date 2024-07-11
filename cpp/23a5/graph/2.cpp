// largest number of edges in a bipartie with n nodes

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // ap dung am-gm
    cout << (n / 2) * (n / 2 + (n % 2));
}