#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(2*n);
    for (int &x : a) cin >> x;

    vector<int> cnt(n+1); for (int i = 0; i < n; i++) cnt[a[i]]++;

    k *= 2;

    vector<int> g0, g1, g2;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) g0.push_back(i);
        else if (cnt[i] == 1) g1.push_back(i);
        else g2.push_back(i);
    }

    int v = 0;
    for (auto x : g2) {
        if (v < k) {
            v += 2;
            cout << x << ' ' << x << ' ';
        }
    }
    for (auto x : g1) {
        if (v < k) {
            v++;
            cout << x << ' ';
        }
    }
    cout << '\n';

    v = 0;
    for (auto x : g0) {
        if (v < k) {
            v += 2;
            cout << x << ' ' << x << ' ';
        }
    }
    for (auto x : g1) {
        if (v < k) {
            v++;
            cout << x << ' ';
        }
    }

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}