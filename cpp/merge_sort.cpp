#include <iostream>
#include <algorithm>
using namespace std;

int a[10005];
void merge_sort(int l, int r) {
    if (l >= r) return;

}

int main()
{
    int n; cin >> n; for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n-1);

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
}