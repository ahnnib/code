#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int n, k; string s;

void sub1() {
    int res = 0;
    // ko xoa ki tu nao
    for (int i = 0; i < s.size(); i++) {
        int j = i, len = 0; while (j < s.size() && s[j] == s[i]) j++, len++;
        i = j - 1;
        res = max(res, len);
    }
    // xoa 1 loai ki tu
    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int i = 0; i < s.size(); i++) {
            int j = i, len = 0;
            while (j < s.size()) {
                if (s[j] != s[i] && s[j] != ch) break;
                if (s[j] == s[i]) len++;
                j++;
            }
            i = j - 1;
            res = max(res, len);
        }
    }
    cout << res;
}
void sub2() {
    int res = 0;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) len++;
        }
        res = max(res, len);
    }
    cout << res;
}
void ac() {
    /*
    duyet cac vi tri r
    voi moi r tim l nho nhat sao cho xau [l, r] co k+1 loai ki tu khac nhau
    tim loai ki tu xuat hien nhieu nhat
    */
    int nd = s.size();
    int l = 0;
    int cnt[123] = {};
    int unique = 0;

    auto add = [&](char ch) -> void {
        unique += (++cnt[ch] == 1);
    };
    auto del = [&](char ch) -> void {
        unique -= (--cnt[ch] == 0);
    };

    int res = 0;
    for (int r = 0; r < nd; r++) {
        add(s[r]);

        while (unique > k+1) del(s[l]), l++;

        int t = 0; for (int ch = 'a'; ch <= 'z'; ch++) t = max(t, cnt[ch]);

        res = max(res, t);
    }

    cout << res;
}

int main() {
    cin >> n >> k;
    cin >> s;

    // if (k == 1) sub1();
    // else if (k == 25) sub2();
    // else ac();
    ac();
}