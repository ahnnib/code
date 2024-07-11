#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n, m, a; cin >> n >> m >> a;
    if (n < a) cout << m * n;
    else cout << m * n * 3 / 4;
}
