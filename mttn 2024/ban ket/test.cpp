#include <iostream>
#include <iomanip>
using namespace std;

const long long MOD = 998244353;

long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long modulo_multiplicative_inverse(long long a, long long m) {
    long long x, y;
    extended_euclidean(a, m, x, y);
    return (x % m + m) % m;
}

long long calculate_modulo(long long n) {
    long long result = ((n % MOD) * ((n + 1) % MOD)) % MOD;
    return (result * modulo_multiplicative_inverse(2, MOD)) % MOD;
}

int main() {
    // long long n;
    // cout << "Nhap gia tri cua n: ";
    // cin >> n;
    // cout << "Gia tri cua n * (n + 1) / 2 modulo 998244535 la: " << calculate_modulo(n) << endl;
    // return 0;
    // cout << modulo_multiplicative_inverse(2, MOD);
    float a = (float)1 / 3;
    cout << fixed << setprecision(10) << a;
}