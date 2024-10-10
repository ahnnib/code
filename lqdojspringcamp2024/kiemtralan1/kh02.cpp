#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    if (n > 26) return cout << m, 0;

    cout << m % (1<<n);
}
