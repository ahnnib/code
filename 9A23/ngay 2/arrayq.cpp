#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";
const int max = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

     freopen("arrayq.inp", "r", stdin);
     freopen("arrayq.out", "w", stdout);

    int n; cin >> n; vector<ll> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    int q = 1;
    cin >> q;
    // O(n^2)
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            ll x, y; cin >> x >> y;
            for (int i = 0; i < a.size(); i++) if (a[i] == x) a.insert(a.begin() + i+1, y); // O(n)
        }
        else {
            ll x; cin >> x;
            for (int i = 0; i < a.size(); i++) if (a[i] == x) a.erase(a.begin() + i); // O(n)
        }
    }
    for (int i = 0 ; i < a.size(); i++) cout << a[i] << ' ';
}
