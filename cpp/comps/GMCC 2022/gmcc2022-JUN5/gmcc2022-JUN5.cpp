#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    float a, b, c;
    cin >> a >> b >> c;

    double delta = b * b - 4 * a * c;

    if (a == 0) {
        cout << "irrational number";
        return 0;
    }
    if (delta < 0) {
        cout << "irrational number";
    }
    if (delta == 0) {
        cout << -b / (2 * a);
    }
    if (delta > 0) {
        cout << "x1 = " << fixed << setprecision(2) << (-b + sqrt(delta)) / (2 * a) << '\n';
        cout << "x2 = " << fixed << setprecision(2) << (-b - sqrt(delta)) / (2 * a);
    }
}