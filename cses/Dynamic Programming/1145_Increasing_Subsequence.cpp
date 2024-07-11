#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    vector<int> dp;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vector<int>::iterator it = lower_bound(begin(dp), end(dp), a);
        if (it == dp.end()) dp.push_back(a);
        else *it = a;
    }

    cout << dp.size();
}