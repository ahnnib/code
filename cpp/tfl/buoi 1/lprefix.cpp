#include <iostream>
#include <algorithm>
using namespace std;

string pref(string &s1, string &s2) {
    string res;
    for (int i = 0; i < min(s1.size(), s2.size()) && s1[i] == s2[i]; i++)
        res += s1[i];
    return res;
}

int main()
{
    int n; cin >> n; string w[n]; for (int i = 0; i < n; i++) cin >> w[i];

    sort(w, w + n);

    string res;
    for (int i = 1; i < n; i++) {
        string t = pref(w[i], w[i-1]);
        if (t.size() > res.size()) res = t;
    }

    cout << res;
}
