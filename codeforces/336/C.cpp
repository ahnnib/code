#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n; cin >> n; int a[100000]; for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> res;
    for (int i = 0; i < 30; i++) {
        int sum = (1<<30) - 1;
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if ((a[j]>>i) & 1) {
                v.push_back(a[j]);
                sum &= a[i];
            }
        }
        if (sum % (1<<i) == 0) res = v;
    }
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}