#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);

    int n; cin >> n; string s; cin >> s;
    int cnt[123] = {}; for (int i = 0; i < n; i++) cnt[s[i]]++;

    int r = n-1, ch = 'a';
    string binh, an;
    while (r >= 0) {
        while (r >= 0 && s[r] == ',') r--;
        if (r >= 0) cnt[s[r]]--, an += s[r], s[r] = ',';
        while (ch <= 'z' && cnt[ch] < 1) ch++;
        if (ch > 'z') break;
        int L = r-1; while (L >= 0 && s[L] != ch) L--;
        binh += s[L]; s[L] = ','; cnt[ch]--;
    }
    // cout << an << '\n' << binh;
    an += '0'; binh += '0';
    for (int i = 0; i< min(an.size(), binh.size()); i++){
        if (an[i] < binh[i]) return cout << "NO", 0;
        else if (binh[i] < an[i]) {
            cout << "YES\n";
            for(int j = 0; j < binh.size()-1; j++) cout << binh[j];
            return 0;
        }
    }
    cout << "NO";
}