#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) see(a[i]);
#define debug cout << "dfad\n";

bool prime(long long n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i+2) == 0) return 0;
    return 1;
}

signed main()
{
    for (int m = 1; m <= 12; m++) {
        int t;
        if (m == 1) t = 31;
        if (m == 2) t = 28;
        if (m == 3) t = 31;
        if (m == 4) t = 30;
        if (m == 5) t = 31;
        if (m == 6) t = 30;
        if (m == 7) t = 31;
        if (m == 8) t = 31;
        if (m == 9) t = 30;
        if (m == 10) t = 31;
        if (m == 11) t = 30;
        if (m == 12) t = 31;
        for (int d = 1; d <= t; d++) {
            string st = to_string(d) + to_string(m);
            if (prime(stoi(st))) cout << to_string(d) << '/' << to_string(m) << '\n';
        }
    }
}