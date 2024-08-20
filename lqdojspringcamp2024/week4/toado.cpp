// Cho 2 điểm nguyên A(m, n), B(p, q). Đếm số lượng điểm nguyên giữa A và B.
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int m, n, p, q; cin >> m >> n >> p >> q;
    int dx = p - m, dy = n - q;
    cout << __gcd(dx, dy) - 1;
}