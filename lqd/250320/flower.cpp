#include <bits/stdc++.h>
using namespace std;

// Segment Tree class
class SegmentTree {
private:
    vector<long long> tree;
    int n;

    void build(const vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, long long value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return LLONG_MIN; // Out of range
        }
        if (l <= start && r >= end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        long long left_query = query(2 * node + 1, start, mid, l, r);
        long long right_query = query(2 * node + 2, mid + 1, end, l, r);
        return max(left_query, right_query);
    }

public:
    SegmentTree(int size) : n(size), tree(4 * size, LLONG_MIN) {}

    void build(const vector<long long>& arr) {
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, long long value) {
        update(0, 0, n - 1, idx, value);
    }

    long long query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

int main() {
    freopen("flower.inp", "r", stdin);
    freopen("flower.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(n);
    SegmentTree segTree(n);

    dp[0] = a[0];
    segTree.update(0, dp[0]);

    for (int i = 1; i < n; ++i) {
        // Query the maximum value in the range [i-k to i-1]
        long long max_prev = (i - k >= 0 ? segTree.query(i - k, i - 1) : segTree.query(0, i - 1));
        dp[i] = a[i] + max_prev;
        segTree.update(i, dp[i]);
    }

    // Find the maximum value in the last k elements
    long long result = LLONG_MIN;
    for (int i = n - k; i < n; ++i) {
        result = max(result, dp[i]);
    }

    cout << result << "\n";
    return 0;
}
