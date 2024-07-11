#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("minnum.inp", "r", stdin);
    freopen("minnum.out", "w", stdout);
    #endif

    string s; cin >> s;
    char old = s[0];
    int cnt = 0, t = 0;
    for (char ch : s) {
        if (ch != old) cnt = 0, old = ch;
        cnt++;
        t = max(t, cnt);
    }
    cout << t;
}