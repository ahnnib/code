#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    string s = "012345";
    cout << s.substr(1, 3);
}
/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

bool isnum(char ch) { return '0' <= ch && ch <= '9'; }

bool cmp(string a, string b) { // a <= b
    if (a.size() < b.size()) return 1;
    if (a.size() > b.size()) return 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return 1;
}

int main() {
    freopen("timso.inp", "r", stdin);
    freopen("timso.out", "w", stdout);

    string s; cin >> s; vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (isnum(s[i])) {
            string num;
            while (i < s.size() && isnum(s[i])) num += s[i++];
            while (num.size() > 1 && num[0] == '0') num.erase(0, 1);
            v.push_back(num);
        }
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0] << '\n' << v[v.size()-1];
}
*/