#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int main() {
    int n; cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    int max_end = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        max_end = max(max_end, a[i].second);
        if (a[i].second < max_end) cnt++;
    }
    cout << cnt;
}