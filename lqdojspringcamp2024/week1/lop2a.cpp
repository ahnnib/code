// https://lqdoj.edu.vn/problem/lop2a
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll a1, b1, a2, b2; cin >> a1 >> b1 >> a2 >> b2;
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    ll t1 = __gcd(a1, a2), t2 = __gcd(b1, b2);
    // a1 / a2 = b1 / b2
    if (a1 / t1 == b1 / t2 && a2 / t1 == b2 / t2) cout << "YES";
    else cout << "NO";
}