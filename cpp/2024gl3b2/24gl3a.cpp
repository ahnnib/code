#include <iostream>
using namespace std;

int main()
{
    long long n; cin >> n;

    cout << -1 * (n / 2) + (n % 2 ? n : 0);
}