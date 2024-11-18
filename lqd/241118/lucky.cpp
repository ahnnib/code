#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    // freopen("lucky.inp", "r", stdin);
    // freopen("lucky.out", "w", stdout);
    ll n;
    cin >> n;

    int len = 1;
    while (n > (1<<len)) {
        n -= 1<<len;
        len++;
    }

    n -= 1;
    string bin;
    while (n > 0) {
        bin.push_back(n % 2 + 48);
        n /= 2;
    }
    while (bin.size() < len) bin += '0';

    for (int i = bin.size()-1; i >= 0; i--)
        cout << (bin[i] == '1' ? 7 : 4);
}