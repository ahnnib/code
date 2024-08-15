// n <= 1e9
#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

bool prime(int x) {
    if (x <= 3) return x > 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (int i = 5; i*i <= x; i += 6) {
        if (x%i == 0 || x %(i+2) == 0) return 0;
    }
    return 1;
}
int main() {
    int n; cin >> n;
    for (int a = n / 2; a >= 1; a--) {
        if (prime(a) && prime(n-a)) {
            cout << a << ' ' << n-a << '\n';
            return 0;
        }
    }
}