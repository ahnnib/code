#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const ll m = 1e9 + 7;

int main() {
    ll n, k; cin >> n >> k;
    ll res = 1;
    while (k) {
        if (k & 1) res = res * n % m;
        n = n * n % m;
        k >>= 1;
    }
    cout << res;
}
/*
số tập con k phần tử khác nhau (có thể lặp) trong các số từ 1 -> n
vd: (1, 2), (2, 2), (2, 1) là các tập khác nhau thỏa mãn
---
có k slot có thể chọn từ 1 -> n => n^k
*/