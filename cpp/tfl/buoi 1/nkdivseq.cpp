#include <iostream>
using namespace std;

int cal(int a, int b)
{ // so dau tien > a chia het b
    return b * (a / b + 1);
}

int main()
{
    int n; cin >> n;

    if (n == 1) return cout << 1, 0;

    n--;

    int first = 1, last = 1, i = 1;
    for (; n >= i; i++)
    {
        // cout << first << ' ' << last << '\n';
        first = cal(last, i+1);
        last = first + (i+1) * i;
        n -= i;
    }
    cout << first + i * n << ' ';
    // cout << n << ' ' << i << ' ' << first << ' ' << last;
}
/*
1 | 2 4 | 6 9 12 | 16 20 24 28
*/
