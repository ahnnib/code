#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    long long a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long max_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_here = max(max_here, a[i]);
        cout << max_here * b[i] << '\n';
    }
}