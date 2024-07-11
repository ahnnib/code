#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define int long long

pair<int, int> ss0(int n) {
    int cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0) n /= 2, cnt2++;
    while (n % 5 == 0) n /= 5, cnt5++;
    return {cnt2, cnt5};
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first + a.second >= b.first + b.second) {
        return abs(a.first - a.second) < abs(b.first - b.second);
    }
}

signed main()
{
    int n, k; cin >> n >> k;
    vector< pair<int, int> > res;
    int a; for (int i = 0; i < n; i++) {
        cin >> a;
        res.push_back(ss0(a));
    }
    sort(res.begin(), res.end(), cmp);
    for (auto i : res) cout << i.first << ' ' << i.second << '\n';

    int c2 = 0, c5 = 0;
    for (int i = 0; i < k; i++) {
        c2 += res[i].first;
        c5 += res[i].second;
    }
    cout << min(c2, c5);
}
/*
50 4 20
{1, 2}
{2, 0}
{2, 1}

15 16 3 25 9
{0, 1}
{4, 0}
{0, 2}
*/
