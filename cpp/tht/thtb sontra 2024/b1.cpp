#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void cout(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void coutl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

const string S = "SONTRA";

signed main()
{
    int n; see(n);
    put(S[(n - 1) % 6]);
}