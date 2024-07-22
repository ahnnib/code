#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

const int N = 1e5 + 7;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) : n(size) {
        tree.resize(4 * n, 0);
    }

    void update(int idx, int val, int node, int start, int end) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, val, 2 * node, start, mid);
            } else {
                update(idx, val, 2 * node + 1, mid + 1, end);
            }
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int L, int R, int node, int start, int end) {
        if (R < start || L > end) {
            return 0;
        }
        if (L <= start && end <= R) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftQuery = query(L, R, 2 * node, start, mid);
        int rightQuery = query(L, R, 2 * node + 1, mid + 1, end);
        return max(leftQuery, rightQuery);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n - 1);
    }

    int query(int L, int R) {
        return query(L, R, 1, 0, n - 1);
    }
};

int main() {
    int n; cin >> n;
    int r[n+1] = {}, h[n+1] = {}; 
    for (int i = 1; i <= n; i++) cin >> r[i] >> h[i];
    
    SegmentTree st(N);
    for (int i = n; i >= 1; i--) {
        int t = st.query(1, r[i] - 1);
        st.update(r[i], t + h[i]);
    }

    for (int i = 1; i <= 100; i++) cout << st.tree[i] << ' ';
    cout << st.query(1, N - 1) << endl;

    return 0;
}
