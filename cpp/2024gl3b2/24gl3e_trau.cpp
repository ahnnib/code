#include <iostream>
#include <math.h>
using namespace std;

#define int long long

signed main()
{
    int n, k; cin >> n >> k;

    // cout << ceil((long double) 5 / 2);
    int trau = 0;
    for (int i = 1; i <= k; i++) trau += ceil(n / i);
    for (int i = 1; i <= k; i++) cout << ceil(n / i) << ' ';

    cout << trau;
}
/*
tìm số cuối cùng sao cho n / i = k
-> n = k * i

ví dụ: n = 20
1 2 4 5 10 20
tính số số 1:
lấy 20 / (1+1) = 10
số số 2:
20 / (2+1) = 6

50
1 2 5 10 25 50
50 / 50 = 1
50 / 25 = 2
-> 50 / 26 = 1
50 /
số cận biên: n / i
*/