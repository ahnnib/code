#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("substrk.inp", "r", stdin);
    freopen("substrk.out", "w", stdout);
    int k; string s; cin >> k >> s;
    int ns = s.size(); s = ' ' + s;
    map<int, int> cnt;
    ll res = 0, sum = 0; cnt[0] = 1;
    // a[i] - a[j-1] = k -> a[j-1] = a[i] - k
    for (int i = 1; i <= ns; i++) {
        sum += (s[i] == '1');
        res += cnt[sum - k];
        cnt[sum]++;
    }
    cout << res;
}