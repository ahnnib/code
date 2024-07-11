/*
#include <iostream>
#include <vector>
using namespace std;

int n, m, a[200001]; string s;

int st[4000007];
void build(int id, int l, int r) {
    if (l == r) { st[id] = a[l] % m; return; }
    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = (st[2*id] % m * st[2*id+1] % m) % m;
}
int get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 1;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return (get(2*id, l, mid, u, v) % m * get(2*id+1, mid+1, r, u, v) % m) % m;
}

void solve() {
    cin >> n >> m; for (int i = 1; i <= n; i++) cin >> a[i]; cin >> s;

    build(1, 1, n);

    int l = 1, r = n;
    for (char i : s) {
        cout << get(1, 1, n, l, r) << ' ';
        if (i == 'L') l++;
        else r--;
    }

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}
*/
#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
    int n, m; cin >> n >> m; vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i]; string s; cin >> s;

    /*
    find the index of the number which will be removed last
    do all the operations in reverse order
    division -> multiplication
    */

    int L = 0, R = n-1;
    for (char i : s) {
        if (i == 'L') L++;
        if (i == 'R') R--;
    }

    vector<int> res;

    if (s[n-1] == 'L') {
        L--;
        res.push_back(a[L] % m);
    }
    else {
        R++;
        res.push_back(a[R] % m);
    }


    for (int i = n-2; i >= 0; i--) {
        if (s[i] == 'L') res.push_back(res[res.size()-1] * a[--L] % m);
        else res.push_back(res[res.size()-1] * a[++R] % m);
    }

    for (int i = n-1; i >= 0; i--) cout << res[i] << ' ';

    cout << '\n';
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}
