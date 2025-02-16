#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

ll n, a, b, A[1000001];

void sub2() {
    cout << (n + n % 2) / 2 * (a + b);
}

int main() {
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    map<ll, bool> mark; bool s2 = true;
    for (int i = 0; i < n; i++) {
        if (mark[A[i]]) s2 = false;
        mark[A[i]] = true;
    }

    if (s2) sub2();
}