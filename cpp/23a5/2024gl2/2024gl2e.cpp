#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define int long long

long long scp(int l, int r) { return floor(sqrt(r)) - ceil(sqrt(l)) + 1; }

signed main()
{
    int k; cin >> k;

    if (k == 3) { cout << 9; return 0; }

    long long l = 1, r = 9, nd = 1;
    while (1)
    {
        if (k < scp(l, r) * nd) break;
        k -= scp(l, r) * nd;
        l *= 10, (r *= 10) += 9, nd++;
    }

    int t1 = (k % nd + nd - 1) % nd; // pos
    int t2 = k / nd + (k % nd != 0); // num

    long long res = scp(1, r / 10) + t2;

    cout << to_string(res * res)[t1];
}
/*
xxxxx
 .
    20
   19
  18
 17
16
  .

5 - (20 - 17) - 1 - 1
*/