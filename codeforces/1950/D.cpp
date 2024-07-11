#include <iostream>
#include <vector>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";

/*
11
110

101
1010
1111
1212
*/
bool bin(int x) {
    while (x) {
        if (x % 10 != 0 && x % 10 != 1) return 0;
        x /= 10;
    }
    return 1;
}
void solve() {
    int n; see(n);

    if (bin(n)) {
        cout << "YES\n";
        return;
    }

    /*
    n là tích các số dạng bin
    -> các số đó phải là ước của n
    -> duyệt qua các ước, lưu lại các ước bin

    duyệt qua các ước bin, chia đến khi n ko chia đc nữa
    nếu n = 1 tức là có thể tách n thành tích các ước bin đó -> YES
    ngược lại -> NO
    (giống cài đặt phân tích thừa số nguyên tố)
    */
    vector<int> bindiv;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (bin(i)) bindiv.push_back(i);
            if (i != n/i && bin(n/i)) bindiv.push_back(n/i);
        }
    }

    for (int x : bindiv) {
        // cout << x << ' ';
        while (n % x == 0) n /= x;
    }

    if (n == 1) cout << "YES";
    else cout << "NO";

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}