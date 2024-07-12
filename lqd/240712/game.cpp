#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    // freopen("game.inp", "r", stdin);
    // freopen("game.out", "w", stdout);

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
    auto cmp = [&](string a, string b) -> bool { // a < b -> a thang
        bool c; if (a.size() > b.size()) swap(a, b), c = 1;
        int i = 0;
        for (i < a.size(); i++) {
            if (a[i] < b[i]) return (a[i] < b[i]) ^ c;
            if (a[i] > b[i]) return (a[i] > b[i]) ^ c;
        }
        return (a.size() < b.size()) ^ c;
    };
    if (cmp(binh, an)) cout << "YES";
    else cout << "NO";
    cout << '\n' << binh;
}