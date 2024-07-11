#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    map<int, int> d;
    int res = 0;
    int a[n]; for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]]++;
        // ai + aj2 = k
        // ai = k - aj2
        res += d[k - a[i] * a[i]];
    }
    cout << res;
}