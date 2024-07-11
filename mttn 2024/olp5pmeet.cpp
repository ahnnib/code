#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    long double x1, x2, v1, v2; cin >> x1 >> x2 >> v1 >> v2;

    if (x1 > x2) swap(x1, x2), swap(v1, v2); // xe 1 dung truoc

    if (x1 != x2 && v1 <= v2) return cout << -1, 0;

    long double res = (x2 - x1) / (v2 - v1);

    cout << fixed << setprecision(4) << abs(res);
}
