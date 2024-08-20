#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int a, b, x, y;

int gcd ( int a, int b, int &x, int &y ) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = gcd ( b, a%b, x1, y1 );
    x = y1;
    y = x1 - a/b * y1;
    return g;
}

int main() {
    cin >> a >> b;
    cout << gcd(a, b, x, y) << ' ' << x << ' ' << y;
}