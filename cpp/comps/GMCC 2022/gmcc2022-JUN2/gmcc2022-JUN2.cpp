#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;

    cout << "Max: " << max(a, max(b, max(c, max(d, e))));
    cout << ", Min: " << min(a, min(b, min(c, min(d, e))));
    cout << fixed << setprecision(2) << ", Average: " << (a + b + c + d + e) / 5.00;

    return 0;
}
