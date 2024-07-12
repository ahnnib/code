#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool isnum(char ch) { return '0' <= ch && ch <= '9'; }
bool isprime(int n) {
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return 0;
    }
    return 1;
}
void check(int &res, string &num) {
    for (int i = 0; i < num.size(); i++) {
        for (int j = i; j < num.size(); j++) {
            int t = stoi(num.substr(i, j-i+1));
            if (isprime(t)) res = max(res, t);
        }
    }
}
int main() {
    freopen("matkhau.inp", "r", stdin);
    freopen("matkhau.out", "w", stdout);

    string s, ss; while (cin >> ss) s += ss;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isnum(s[i])) {
            string num;
            while (i < s.size() && isnum(s[i])) num = num + s[i++];
            // cout << num << '\n';
            check(res, num);
        }
    }
    cout << res;
}