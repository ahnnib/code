#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("matkhau.inp", "r", stdin);
    freopen("matkhau.out", "w", stdout);
    #endif

    string s; getline(cin, s);

    ll sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('0' <= s[i] && s[i] <= '9' && !(s[i] & 1)) sum += s[i] - 48;
    }

    ll t = 1;
    ll nd = s.size(); while (nd > 0) nd /= 10, t *= 10;

    cout << sum * t + s.size();
}
