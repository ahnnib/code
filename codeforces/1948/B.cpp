#include <iostream>
#include <vector>
using namespace std;

int fi(int x) { return (x > 9 ? x / 10 : x % 10); }
int se(int x) { return x % 10; }

void solve() {
    int n; cin >> n;
    vector<int> v{0}; bool dig = 1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < 9) v.push_back(a);
        else if (fi(a) <= se(a) && dig && se(v[v.size()-1]) <= fi(a)) {
            v.push_back(fi(a)); v.push_back(se(a));
        }
        else v.push_back(a), dig = 0;
    }

    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] > v[i+1]) { cout << "NO\n" ; return; }
    }

    cout << "YES\n";
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}