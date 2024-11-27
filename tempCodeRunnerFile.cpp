#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    map<int, int> mp;
    mp[2] = 1;
    for (auto &i : mp) i.second = 0;
    cout << mp[2];
}