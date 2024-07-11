#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";
const long double eps = 1e-6;

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        long double xa, xb, xc, xd, t1, t2; cin >> xa >> xb >> xc >> xd >> t1 >> t2;
        if (t1 == 0 && t2 == 0) cout << "Cun\n";
        else if (t1 == 0) cout << "Rua\n"; // rua dich chuyen tuc thoi
        else if (t2 == 0) cout << "Tho\n"; // tho dich chuyen tuc thoi

        else {
            long double v1 = abs((xb - xa) / t1); // rua
            long double v2 = abs((xd - xc) / t2); // tho
            if (abs(v1 - v2) <= eps) cout << "Cun";
            else if (v1 > v2) cout << "Rua";
            else cout << "Tho";
            cout << '\n';   
        }

    }
}

