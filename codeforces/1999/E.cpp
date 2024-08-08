#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 2e5 + 1;
int a[N], s[N];

int f(int x) { int cnt = 0; while (x) x /= 3, cnt++; return cnt; }

void pp() {
    for (int i = 1; i < N; i++) {
        a[i] = f(i);
        s[i] = s[i-1] + a[i];
    }
}

void solve() {
    int l, r; cin >> l >> r;
    cout << s[r] - s[l-1] + a[l] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pp();
    int t = 1;
    cin >> t;
    while(t--) solve();
}