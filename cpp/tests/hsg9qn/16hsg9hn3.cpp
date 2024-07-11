#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("cau3.inp", "r", stdin);
    freopen("cau3.out", "w", stdout);
    #endif

    int k; string s;
    cin >> k >> s;

    vector<string> v;
    for (int i = 0; i <= s.size(); i++)
    {
        s += s[0];
        s.erase(0, 1);
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    if (k > s.size()) cout << -1;
    else cout << v[k-1];
}