#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

}
/*
5
5
1 2 3 4 5
8
8 2 3 1 1 7 4 3
5
3 3 3 3 3
1
1
2
2 1

3 1 0 0 0

n, dãy a. Tách dãy a thành 2 dãy s, t sao cho p(s) + p(t) min
hàm p: cho bộ b m số. p(b) = số số cặp b[i] < b[i+1] => bài toán LIS (dp)

*/