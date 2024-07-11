#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    #else
    freopen("baib.piandsigma.inp", "r", stdin);
    freopen("baib.piandsigma.out", "w", stdout);
    #endif

    int n, k; cin >> n >> k;
    vector<int> am, duong;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (a < 0) am.push_back(-a); else duong.push_back(a);
    }

    sort(am.begin(), am.end(), greater<int>());
    sort(duong.begin(), duong.end(), greater<int>());

    int i = 0;
    int na = am.size(), nd = duong.size();
    // 5 3
    int conlai = nd - k;
    if (conlai < 0)



}