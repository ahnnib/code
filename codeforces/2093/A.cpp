#include <iostream>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

int k;
void sol() {
    cin >> k;
    cout << (k & 1 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) sol();
}