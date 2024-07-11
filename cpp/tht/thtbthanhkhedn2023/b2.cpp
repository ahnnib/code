#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

const int N = 1e6;

int main() {
    #ifndef ONLINE_JUDGE
    #else
    freopen("tongnt.inp", "r", stdin);
    freopen("tongnt.out", "w", stdout);
    #endif

    int n; cin >> n;

    bool com[N] = {};
    com[0] = com[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (com[i] == 0) {
            for (int j = i * i; j < N; j += i) {
                com[j] = 1;
            }
        }
    }
    // tính m
    int m = 0, s = 2; for (int i = 3; i < n; i++) if (!com[i]) { s += i; if (!com[s]) m++; }
    cout << m << '\n';

    s = 2;
    for (int i = 3; i < n; i++) {
        if (!com[i]) {
            s += i;
            if (!com[s]) {
                // in ra
                for (int j = 2; j < i; j++) if (!com[j]) cout << j << '+';
                cout << i << '=' << s << '\n';
            }
        }
    }
}
