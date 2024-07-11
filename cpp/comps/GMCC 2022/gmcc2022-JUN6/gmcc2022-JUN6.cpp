#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float calc_dist(int x1, int y1, int x2, int y2)
{
    return sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2));
}

int main()
{
    int x, y;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;

    // why is the result 109.75 and 128.30? \
    // while the un-rounded answer is 109.756 and 128.296

    cout << fixed << setprecision(2) << calc_dist(x, y, -20, 5)
                                      + calc_dist(-20, 5, 5, 7)
                                      + calc_dist(5, 7, 20, 0)
                                      + calc_dist(20, 0, -2, -10)
                                      + calc_dist(-2, -10, -15, 10)
                                      + calc_dist(-15, 10, x, y);

    return 0;
}