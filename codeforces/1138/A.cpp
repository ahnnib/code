#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n; int t[n+1] = {}; for (int i = 0 ; i < n; i++) cin >> t[i];

    int cnt = 1; vector<int> c;
    for (int i = 0; i < n; i++) {
        if (t[i] == t[i+1]) cnt++;
        else c.push_back(cnt), cnt = 1;
    }
    int res = 0; for (int i = 0; i < c.size()-1; i++) res = max(res, min(c[i], c[i+1]));

    cout << (res<<1);
}