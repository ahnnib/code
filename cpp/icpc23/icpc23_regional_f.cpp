// https://oj.vnoi.info/problem/icpc23_regional_f
#include <iostream>
#include <vector>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

void solve() {
    string a, b; cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "NO\n";
        return;
    }

    vector<int> cnt(123);
    for (int i = 0; i < a.size(); i += 2) cnt[a[i]]++;
    for (int i = 0; i < a.size(); i += 2) cnt[b[i]]--;

    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] != 0) {
            cout << "NO\n";
            return;
        }
    }

    cnt.clear();
    for (int i = 1; i < a.size(); i += 2) cnt[a[i]]++;
    for (int i = 1; i < a.size(); i += 2) cnt[b[i]]--;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int pbt; cin >> pbt; while (pbt--) {
        solve();
    }
}