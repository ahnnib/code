#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
const ll mod = 1e9 + 7;
const ll bs = 521;
const int N = 1e5 + 5;
ll hs[N], ht[N], pow[N]; string s, t; int ns, nt;
ll gets(int l, int r) {
    return (hs[r] - hs[l-1] * pow[r-l+1] % mod + mod) % mod;
}
ll gett(int l, int r) {
    return (ht[r] - ht[l-1] * pow[r-l+1] % mod + mod) % mod;
}
void sub1() {
    pow[0] = 1; for (int i = 1; i < N; i++) pow[i] = pow[i-1] * bs % mod;
    for (int i = 1; i <= ns; i++) {
        hs[i] = (hs[i-1] * bs + s[i] - 'a' + 1) % mod;
    }
    for (int i = 1; i <= nt; i++) {
        ht[i] = (ht[i-1] * bs + t[i] - 'a' + 1) % mod;
    }
    vector<string> v;
    for (int i = 1; i <= ns; i++) {
        for (int j = i; j <= ns; j++) {
            int len = j - i + 1;
            for (int z = 1; z+len-1 <= nt; z++) {
                if (gets(i, j) == gett(z, z+len-1)) {
                    v.push_back(s.substr(i, j-i+1));
                }
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v[v.size()-1];
}
int main() {
    freopen("substring.inp", "r", stdin);
    freopen("substring.out", "w", stdout);
    cin >> s >> t;
    ns = s.size(), nt = t.size();
    s = ' ' + s; t = ' ' + t;
    if (ns <= 5000 && nt <= 5000) sub1();
}