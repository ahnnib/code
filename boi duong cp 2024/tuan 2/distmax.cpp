#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define x first
#define y second

int main()
{
    int n; cin >> n; pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a, a + n);

    int res = abs(a[n-1].x - a[0].x), key = 0;
    for (int i = 0; i < n; i++) {
        while (a[key].x == a[key+1].x) key++;
        if ()
    }
}