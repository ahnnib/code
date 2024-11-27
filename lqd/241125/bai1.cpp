#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

bool nguyenam(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'y';
}

int main() {
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);

    int cnt = 0;
    int n; cin >> n; while (n--) {
        string word; cin >> word;
        for (int i = 0; i < word.size(); i++) {
            int len = 0;
            while (nguyenam(word[i])) {
                len++;
                i++;
            }
            if (len > 0) cnt++, i--;
        }
    }
    cout << cnt;
}