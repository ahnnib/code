#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int N = 1e7 + 1;
bool com[N];
int cnt_res[1000001];
ll sum_res[1000001];
int rev(int x) {
    int r = 0;
    for (; x; x /= 10) r = r * 10 + x % 10;
    return r;
}
bool ok(int x) {
    int xx = rev(x);
    return !com[x] && !com[xx] && x != xx;
}
void sieve() {
    com[0] = com[1] = 1;
    for (int i = 2; i*i < N; i++) if (!com[i])
        for (int j = i*i; j < N; j += i) com[j] = 1;
    for (int i = 2; i < 1000001; i++) {
        cnt_res[i] = cnt_res[i-1] + ok(i);
        sum_res[i] = sum_res[i-1] + !com[i] * 1ll * i;
    }
}

int a, b;
void sol() {
    cin >> a >> b;
    cout << sum_res[b] - sum_res[a-1] << ' ' << cnt_res[b] - cnt_res[a-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("twins.inp", "r", stdin);
    freopen("twins.out", "w", stdout);
    sieve();
    int t = 1;
    cin >> t;
    while(t--) sol();
}