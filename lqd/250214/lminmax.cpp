#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

const int N = 1e6;
int n, diff, a[N];

int main() {
    cin >> n >> diff;
    for (int i = 0; i < n; i++) cin >> a[i];

    deque<int> mn, mx; // min, max deque

    int l = 0;
    int res = 0;
    for (int r = 0; r < n; r++) {
        while (!mn.empty() && a[mn.back()] >= a[r]) {
            mn.pop_back();
        }
        mn.push_back(r);
        while (!mx.empty() && a[mx.back()] <= a[r]) {
            mx.pop_back();
        }
        mx.push_back(r);

        // sliding window
        while (a[mx.front()] - a[mn.front()] > diff) {
            l++;
            // remove indexes that are out of current window
            if (!mn.empty() && mn.front() < l) mn.pop_front();
            if (!mx.empty() && mx.front() < l) mx.pop_front();
        }

        res = max(res, r - l + 1);
    }

    cout << res;
}
/*
min max sparse table + binary search
nhan xet: tu vi tri i di ra xa thi delta cang lon -> binary search
*/