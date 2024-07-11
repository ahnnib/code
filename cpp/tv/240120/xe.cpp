#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // freopen("xe.inp", "r", stdin);
    // freopen("xe.out", "w", stdout);

    int n; cin >> n;
    long long sum = 0; vector<int> pos;
    long long xe[n]; for (int i = 0; i < n; i++) {
        cin >> xe[i];
        sum += xe[i];
        if (xe[i] > 20) pos.push_back(i+1);
    }

    cout << sum << '\n';
    if (pos.empty()) cout << 0;
    else for (int i : pos) cout << i << '\n';
}