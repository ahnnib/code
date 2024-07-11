#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    int l = 1e9, r = 0;
    for (int i = 0; i < n; i++) {
        int heo; cin >> heo;
        l = min(l, heo); r = max(r, heo);
    }
    cout << l << ' ' << r << '\n';
    cout << (ceil((r - l + 1) / k) - 1) / 2;
}
/*
k(2R + 1) >= r - l + 1
R >= ((r - l + 1) / k - 1) / 2
1, 6, 11
12, 17, 22

*/