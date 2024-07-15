#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    ll a; cin >> a;
    // cout << (int)log10(a)+1;
    cout << __builtin_log10(a)+1;
}