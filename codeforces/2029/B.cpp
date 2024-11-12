#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int n; cin >> n;
    string s, r; cin >> s >> r;

    /*
    moi lan remove tu xau s -> mat di 1 luong so 1 va 0 bang nhau
    dem cnt0, cnt1 trong s
    for i qua r
    if (cnt0 == 0 || cnt1 == 0) NO
    cnt0--, cnt1--
    neu ri la 1 cnt1++
    else cnt0++
    */

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }

    bool ok = 1;
    for (int i = 0; i < n-1; i++) {
        if (cnt0 == 0 || cnt1 == 0) {
            ok = 0;
            break;
        }

        cnt0--, cnt1--;
        if (r[i] == '1') cnt1++;
        else cnt0++;
    }

    cout << (ok ? "YES\n": "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}