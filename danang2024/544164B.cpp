#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 1e6 + 1;
int n, k, a[N], cnt[N];
void sub1() {
    for (int i = 0; i < n; i++) cnt[a[i]]++;
    int len = n / 2 + 1; bool ok = 0;
    for (int i = 1; i < N; i++) {
        if (cnt[i] >= len) cout << i << ' ', ok = 1;
    }
    if (!ok) cout << -1;
}
void sub() {
    for (int i = 0; i <= n-k; i++) {
        for (int j = i; j < i+k-1; j++) cnt[a[j]]++;
        for (int j = i+k-1; j < n; j++) {
            cnt[a[j]]++;
            if (cnt[a[j]] >= (j-i+1) / 2 + 1) troi[a[j]] = 1;
        }
    }
}
int main() {
    cin >> n >> k; for (int i = 0; i < n; i++) cin >> a[i];
    if (k == n) sub1();
}