#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k; cin >> n >> k; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    long long A = 0;

    long long B = 1;

    sort(a, a + n);

    if (B == 0) { cout << 0; }
    if (B < 0) for (int i = 0; i < k; i++) A += a[i];
    if (B > 0) for (int i = n-1; i > n-1-k; i--) A += a[i];

    cout << A;
}