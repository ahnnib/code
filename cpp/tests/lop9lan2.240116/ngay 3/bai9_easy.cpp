#include <iostream>
using namespace std;

bool prime(int n)
{
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i+2) == 0) return 0;
    return 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("bai9.easy.inp", "r", stdin);
    freopen("bai9.easy.out", "w", stdout);
    #endif

    int q; cin >> q;
    while (q --> 0)
    {
        int A; cin >> A;
        for (int B = A-1; B > 1; B--) if (prime(B)) { cout << B << '\n'; break; }
    }
}