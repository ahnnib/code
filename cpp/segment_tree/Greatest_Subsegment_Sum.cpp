/*
https://oj.vnoi.info/problem/gss
q(x, y): max(\sum{a[i] -> a[j]} x <= i <= j <= y)
*/
#include <iostream>
using namespace std;

#define debug cout << "dfad\n";
#define debug2 cout << "dfad2\n";

const int MAX = 5e4 + 7;
const int INF = 1e9 + 7;

struct node { int pre, suf, sum, maxsum; };

int n, m, a[MAX];
node st[4 * MAX];

void f(node n) { cout << n.pre << ' ' << n.suf << ' ' << n.sum << ' ' << n.maxsum << '\n'; }
node merge(node s1, node s2) {
    node res;
    res.pre = max(s1.pre, s1.sum + s2.pre);
    res.suf = max(s2.suf, s1.suf + s2.sum);
    res.sum = s1.sum + s2.sum;
    res.maxsum = max(s1.maxsum, max(s1.suf + s2.pre, s2.maxsum));
    return res;
}
void build(int id, int l, int r) {
    // base case
    if (l == r) { st[id] = {a[l], a[l], a[l], a[l]} ; return; }

    int mid = (l + r) >> 1;
    build(2*id, l, mid); build(2*id+1, mid+1, r);
    st[id] = merge(st[2*id], st[2*id+1]);
}
node get(int id, int l, int r, int x, int y) {
    // base case
    if (l > y || r < x) { return {-INF, -INF, 0, -INF}; }
    if (x <= l && r <= y) { return st[id];  }

    int mid = (l + r) >> 1;
    return merge(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
}

int main()
{
    cin >> n; for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    cin >> m; while (m--) {
        int x, y; cin >> x >> y;
        cout << get(1, 1, n, x, y).maxsum << '\n';
        // f(get(1, 1, n, x, y));
    }
}