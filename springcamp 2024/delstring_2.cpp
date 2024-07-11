#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k;
string s;
int dpp[300];
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> s;
    if (k == 1) {
        ll cnt = 1, res = 0;
        for(int i = 1; i < s.length(); i++){
            if (s[i] == s[i - 1]) cnt++;
            else if (s[i + 1] == s[i - 1]){
                s[i] = s[i - 1];
                cnt--;
            }
            else {
                res = max (res, cnt);
                cnt = 1;
            }
        }
        res = max (res, cnt);
        cout << res; return 0;
    }
        char c;
        ll maxi = 0;
        for (int i = 0; i < s.length(); i++) {
            dpp[s[i]]++;
            if (dpp[s[i]] > maxi) {
                maxi = dpp[s[i]];
                c = s[i];
            }
        }
        cout << dpp[c]; return 0;
}