#include <iostream>
#include <vector>
using namespace std;

#define t first
#define c second
/*
mmmmaappppiee
mmappiiie
*/
void compress(string s, vector< pair<char, int> > &v) {
    for (int i = 0; i < s.size(); i++) {
        char cur = s[i]; int cnt = 0;
        while (i < s.size() && s[i] == cur) i++, cnt++; i--;
        v.push_back({s[i], cnt});
    }
}
bool maximize(int &x, int y) {
    if (x > y) return x = y, 1;
    return 0;
}

void solve() {
    // int n; cin >> n;
    string s; cin >> s;

    vector< pair<char, int> > v;
    compress(s, v); int nd = v.size();

    // for (auto i : v) cout << i.first << ' ' << i.second << '\n';
    int res = 0;
    for (int i = 0; i < nd; i++) {
        string ss; int MIN = 1e6; int pos;
        for (int j = i; j <= i + 5 && j < nd; j++) {
            ss += v[j].t;
        }
        // mapmap
        // piepie
        // mapie
        // cout << ss << '\n';
        if (ss == "mapie") {
            for (int j : {i+2, i+1, i+3})
                if (j < nd && maximize(MIN, v[j].c)) pos = j;
            res += v[pos].c; i = pos; continue;
        }

        while (ss.size() > 3) ss.erase(ss.size()-1, 1);
        // map
        if (ss == "map") {
            for (int j = i; j <= i + 2 && j < nd; j++)
                if (maximize(MIN, v[j].c)) pos = j;
            res += v[pos].c; i = pos; continue;
        }
        // pie
        if (ss == "pie") {
            for (int j = i; j <= i + 2 && j < nd; j++)
                if (maximize(MIN, v[j].c)) pos = j;
            res += v[pos].c; i = pos; continue;
        }
    } // piepiepiepiepie
    // mappie mapmapmap
    cout << res;

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    // long long NTT; cin >> NTT; while (NTT--) {
    //     solve();
    // }
    solve();
}