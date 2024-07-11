#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a) for (auto &x : a) see(x);
#define debug cout << "dfad\n";

bool check(int n, int c0, int c1, int pos) {
    bool ok1 = (c0 >= (pos + 1) / 2);
    bool ok2 = (c1 >= (n - pos + 1) / 2);
    return ok1 && ok2;
}
void solve() {
    int n; string s; see(n, s);

    int pre = 0, suf[n+2] = {};
    for (int i = n-1; i >= 0; i--) suf[i] = suf[i+1] + (s[i] == '1');

    int dist = n * 2;
    int res = 0;
    for (int pos = 0; pos <= n; pos++) {
        // putl(pos, pre[pos], suf[pos+1], check(n, pre[pos], suf[pos+1], pos));
        if (check(n, pre, suf[pos], pos)) {
            if (abs(n - 2 * pos) < dist) {
                dist = abs(n - 2 * pos);
                res = pos;
            }
        }
        if (pos != n) pre += (s[pos] == '0');
    }

    // sort(res.begin(), res.end());
    // sort(res.begin(), res.end(), [&n, &mid](int &a, int &b){
    //     if (a >= b) return abs(mid - a) < abs(mid - b);
    // });
    // for (auto i : res) put(i); cout << '\n';
    cout << res;
    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}