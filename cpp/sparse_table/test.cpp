/*
len < 2^(k+1)
k+1 = log2(len)
k = log2(len) - 1
*/
#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

signed main()
{
    const int MAX = 100;
    for (int len = 0; len <= MAX; len++) {
        // len < 2^(k+1)
        int k = 0;
        while (len >= 1<<(k+1)) k++;
        cout << k << ' ';
    }
    cout << '\n';
    for (int i = 0; i <= MAX; i++) {
        cout << __lg(i) << ' ';
    }
}