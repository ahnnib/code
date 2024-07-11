// Longest Increasing Subsequence problem
// O(N log N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; vector<int> a;

vector<int> s;

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) { s[id] = val; return; }
    int mid = (l + r) >> 1;
    update(2*id, l, mid, pos, val); update(2*id+1, mid+1, r, pos, val);
    s[id] = max(s[2*id], s[2*id+1]);
}
int get(int id, int l, int r, int x, int y) {
    if (x > r || y < l) return 0;
    if (x <= l && r <= y) return s[id];
    int mid = (l + r) >> 1;
    return max(get(2*id, l, mid, x, y), get(2*id+1, mid+1, r, x, y));
}
void print(int node, int from, int to) {
    if(from < to) {
        int mid = (from + to) / 2;
        print(node * 2, from, mid);
        print(node * 2 + 1, mid + 1, to);
    }
    else
        std::cout << s[node] << " ";
}
void _update(int pos, int val) { update(1, 1, n, pos, val); }
int _get(int l, int r) { return get(1, 1, n, l, r); }
void _print() { cout << "Print array\n"; print(1, 1, n); cout << "\n"; }

void compress(vector<int> &v) {
    vector<int> dup = v;
    sort(dup.begin(), dup.end());
    dup.erase(unique(dup.begin(), dup.end()), dup.end());
    for (int i = 0; i < v.size(); i++) {
        v[i] = lower_bound(dup.begin(), dup.end(), v[i]) - dup.begin() + 1;
    }
}

int main()
{
    cin >> n; a.resize(n); s.resize(4 * n + 1); for (int i = 0; i < n; i++) cin >> a[i];

    compress(a);

    for (int i = 0; i < n; i++) {
        // int res = 0;
        // if (1 < a[i]) res = _get(1, a[i] - 1);
        // else res = 0;
        // _update(a[i], res + 1);
        int res = _get(1, a[i] - 1);
        _update(a[i], res + 1);
        // _print();
    }

    cout << _get(1, n);
}