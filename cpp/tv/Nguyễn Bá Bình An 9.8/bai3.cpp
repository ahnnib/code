#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[k];
    for (int i = 0; i < k; i++) cin >> a[i];

    sort(a, a + k, greater<int>());

    set<int> s;
    s.insert(a[0]);
    int i, pos;
    for (i = 0; i < k; i++)
    {
        if (s.size() == n) break;
        if (a[i] != a[i-1]) s.insert(a[i]), pos = i;
    }

    // cout << pos << '\n';
    long long sum = 0;
    for (int i : s) sum += i;

    if (s.size() < n) sum -= a[k-1];
    cout << sum;
}
