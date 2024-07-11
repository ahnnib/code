#include <iostream>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("baia.clone.inp", "r", stdin);
    freopen("baia.clone.out", "w", stdout);
    #endif

    string s, t;
    getline(cin, s); getline(cin, t);

    int ns = s.size(), nt = t.size();
    int k = 0, cnt = 0; // duyet qua t
    for (int i = 0; i < ns; i++)
    {
        if (s[i] == t[k]) k++;
        if (k == nt) k = 0, cnt++;
    }

    cout << cnt * nt;
}