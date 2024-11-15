#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e5 + 1;
bool sang[100001];

int main() {
    freopen("number.inp", "r", stdin);
    freopen("number.out", "w", stdout);
    int n; cin >> n;

    sang[0] = sang[1] = 1;
    for (int i = 2; i*i <= n; i++) if (!sang[i])
        for (int j = i*i; j <= n; j += i) sang[j] = 1;

    auto get = [&](int x) {
        // thay vì hỏi từ 1 -> cnt tốn cnt lần hỏi, có cách tốn log(cnt) lần hỏi
        int nn = n, cnt = 0;
        while (nn >= x) {
            nn /= x;
            cnt++;
        }
        return cnt;
    };

    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (!sang[i]) {
            int t = get(i);
            res += t;
        }
    }
    cout << res;
}