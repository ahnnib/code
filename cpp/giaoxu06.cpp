#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    /*
    AbA
    với mỗi A suy ra một gt b thỏa
    sizeA = n => tìm số số nguyên dương n chữ số
    */

    if (n == 0) cout << 1;
    else { cout << 9; for (int i = 1; i < n; i++) cout << 0; }
}