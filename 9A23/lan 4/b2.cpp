#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";
const double eps = 1e-6;
const double f = 1e6;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        double xa, ya, xb, yb, xc, yc, xd, yd; cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
		double a = (xb - xa) / (yb - ya);
		double a2 = (xd - xc) / (yd - yc);
//		double b = ya - a * xa;
//		double b2 = yc - a2 * xc;
    }
}
