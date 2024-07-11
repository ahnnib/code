#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n == 1) return cout << "YES", 0;
    long long d = a[1] - a[0];
    for (int i = 1; i < n-1; i++)
    {
        if (a[i+1] - a[i] != d) return cout << "NO", 0;
    }
    cout << "YES";
}