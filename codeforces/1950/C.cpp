#include <iostream>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

void solve() {
    int hh; char c; int mm; see(hh, c, mm);

    string s = " AM";
    if (hh >= 12) s = " PM";
    if (hh > 12) hh -= 12;
    if (hh == 0) hh = 12;

    if (hh < 10) cout << 0;
    cout << hh << c;
    if (mm < 10) cout << 0;
    cout << mm << s;

    cout << '\n';
}

// FOR (i, ,) n
//     FOR (j)
        // cout << a[i][j] << " \n"[j == m];
signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}