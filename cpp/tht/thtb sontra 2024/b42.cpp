#include <map>
#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";
#define int long long

signed main()
{
    int n; see(n);

    map<int, int> nt;
    int D = 1, D_le, D_chan;

    // sàng n^2
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            nt[i] += 2;
        }
    }
    if (n > 1) nt[n] += 2;

    // tính D
    for (auto it : nt) {
        D *= (it.second + 1);
    }
    D_le = D / (nt[2] + 1);
    D_chan = D - D_le;

    // for (auto &[x, y] : nt) putl(x  x, y);
    // putl(D, D_chan, D_le);
    if(D_chan == 0)
        return cout << (D_le - 1) / 2, 0;
    cout << (D_chan - D_le - 1) / 2;
}
/*
64
1 2 4 8 16 32 64
3
1

8
2

12
1 2 3 4 6 12
2 * 3^2

*/
