#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    cout << fixed << setprecision(5) << (long double) (1ll * a * b) / (a + b);
}