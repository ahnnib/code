#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool isnum(char ch) { return '0' <= ch && ch <= '9'; }
int main() {
    // freopen("matkhau.inp", "r", stdin);
    // freopen("matkhau.out", "w", stdout);

    string s; cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        int num = 0;
        while (isnum(s[i])) num = num * 10 + (s[i]-48), i++;
        res = max(res, num);
    }
    cout << res;
}