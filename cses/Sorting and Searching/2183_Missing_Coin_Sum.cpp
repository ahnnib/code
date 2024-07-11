#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int c[n]; for (int i = 0; i < n; i++) cin >> c[i];

    sort(c, c + n);

    long long sum = 1;
    for (int i = 0; i < n; i++)
    {
        if (sum < c[i]) return cout << sum, 0;
        sum += c[i];
    }
    cout << sum;
}