// https://lqdoj.edu.vn/problem/incsubseq
#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n; int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    int A = a[0], B = a[1], res = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] <= A) A = a[i];
        else if (a[i] <= B) B = a[i];
        else A = a[i], res++;
        // if (a[i] > A && a[i] > B) A = a[i], res++;
        // else if (A <= a[i] && a[i] <= B) B = a[i];
        // else if (B <= a[i] && a[i] <= A) A = a[i];
        // else B = a[i];
    }

    cout << res;
}