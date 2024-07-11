#include <iostream>
#include <algorithm>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

long long lcm(long long a, long long b) { return a / __gcd(a, b) * b; }
signed main()
{
    long long t1, t2, t3, t4, x, s; see(t1, t2, t3, t4, x, s);

    long long t = lcm(t3 + x, t4 + x);
    t = lcm(t2 + x, t);
    t = lcm(t1 + x, t);

    if (t >= s) put(t - s);
    else {
        int pb = t;
        while (pb < s) pb += t;
        put(pb - s);
    }
}