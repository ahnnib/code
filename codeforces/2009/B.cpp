#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

void sol() {
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int i : {0,1,2,3}) if (s[i] == '#') v.push_back(i+1);
    }
    for (int i = v.size()-1; i >= 0; i--) cout << v[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}