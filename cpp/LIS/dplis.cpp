#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void compress(vector<int> &v) {
    vector<int> dup = v;
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    for (int i = 0; i < v.size(); i++) {
        v[i] = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin() + 1;
    }
}

int main()
{
    int n; cin >> n; vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    compress(a);

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }

    cout << dp.size();
}
