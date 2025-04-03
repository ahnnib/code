#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ull unsigned long long
#define dbg cout << "dfad\n";

bool prime(ull x) {
    if (x <= 3) return x > 1;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (ull i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

bool check(ull x) {
    ull t = (ull)(sqrt(x));
    bool check1 = (t * t == x);

    bool check2 = false;
    ull l = 1, r = 2154435, m;
    while (l <= r) {
        m = (l + r) >> 1;
        if (m * m * m < x) l = m + 1;
        else r = m - 1;
    }
    if (l * l * l == x) {
        check2 = prime(l);
    }
    return check1 || check2;
}

void process(vector<ull> &v, string &s) {
    s = s + ' ';
    ull num = 0;
    for (char i : s) {
        if (i == ' ') {
            if (check(num)) v.push_back(num);
            num = 0;
        }
        else {
            num = num * 10 + (i - 48);
        }
    }
}

int main() {
    string s;

    vector<ull> v1, v2;

    v1.push_back(0);
    v2.push_back(0);

    getline(cin, s);
    process(v1, s);

    getline(cin, s);
    process(v2, s);

    int n1 = v1.size() - 1, n2 = v2.size() - 1;
    int dp[n1 + 1][n2 + 1] = {};
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (v1[i] == v2[j] && v1[i] > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout << dp[n1][n2];
}
/*
2 9 8 4 1 27 4 6
5 6 9 1 8 2 6 27 1 4
4
3 3 6 8 9 4 4 6 2 8 7
3 6 6 2 9 1 2 3 7 8
2
*/