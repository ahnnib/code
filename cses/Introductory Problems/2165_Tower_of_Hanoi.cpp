#include <iostream>
using namespace std;

void move(int n, int rod_a, int rod_b)
{
    // rod_ rod_3 rod_2
    // 1 + 2 + 3 = 6
    if (n == 0) return;
    int rod_aux = 6 - rod_a - rod_b;
    move(n-1, rod_a, rod_aux);
    cout << rod_a << ' ' << rod_b << '\n';
    move(n-1, rod_aux, rod_b);
}

int main()
{
    short n;
    cin >> n;

    cout << (1<<n) - 1 << '\n';
    move(n, 1, 3);
}
