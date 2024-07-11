// https://lqdoj.edu.vn/problem/lop2a
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    long long g1 = gcd(a1, b1),
              g2 = gcd(a2, b2);

    // các cạnh phải tương ứng
    if (a1 < b1) swap(a1, b1);
    if (a2 < b2) swap(a2, b2);

    if (a1 / g1 == a2 / g2 && b1 / g1 == b2 / g2) cout << "YES\n";
    else cout << "NO\n";
}
/*
a1 / b1 = a2 / b2
a1/g1
*/