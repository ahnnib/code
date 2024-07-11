#include <iostream>

const int mod = 0x3B9ACA07;

long long pow2(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 2;

    long long t = pow2(n >> 1) % mod;
    t = t * t % mod;
    if (n % 2) return (t << 1) % mod;
    else return t;

}

int main()
{
    int n;
    std::cin >> n;

    std::cout << pow2(n);
}