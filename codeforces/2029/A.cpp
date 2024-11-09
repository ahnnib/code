#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

void sol() {
    int l, r, k; cin >> l >> r >> k;

    int left = l, right = r, mid;
    while (left <= right) {
        mid = left + right >> 1;
        if (r / mid - (l - 1) / mid >= k) left = mid + 1;
        else right = mid - 1;
    }

    cout << right - l + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}