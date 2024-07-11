#include <iostream>
using namespace std;

/*
6
AABBAA

*/
void solve() {
    int n; cin >> n;

    if (n & 1) cout << "NO";
    else {
        cout << "YES\n";
    for (int i = 0; i < (n>>1); i++) {
        if (i & 1) cout << "AA";
        else cout << "BB";
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