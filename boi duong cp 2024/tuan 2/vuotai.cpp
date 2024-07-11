#include <iostream>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    long long sum = 0, M = 0;
    for (int i = 0; i < n; i++) {
        long long a; cin >> a;
        sum += a;
        M = max(M, a);
    }

    cout << 1 + sum - M + max(0ll, M - k); // cộng 1 để > 0 để sống sót
}