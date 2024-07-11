#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define int long long

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return (a.first + a.second > b.first + b.second && abs(a.first - a.second) < abs(b.first - b.second));
}

signed main()
{
    vector< pair<int, int> > res = {
        {1, 2},
        {4, 9},
        {4, 5},
        {3, 1},
        {3, 3}
    };
    sort(res.begin(), res.end(), cmp);
    for (auto i : res) cout << i.first << ' ' << i.second << '\n';
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
