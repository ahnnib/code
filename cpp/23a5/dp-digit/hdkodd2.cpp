#include <iostream>
#include <math.h>

/*
{1, 3, 5, 7, 9, 111, 113, 115, ...}
tìm số siêu lẻ thứ n
---

tìm độ dài
thử từ 1, 3, 5, 7, …
nếu số lượng nhỏ hơn, trừ bớt vào n
nếu số lượng lớn hơn hoặc bằng, thì dừng
lần lượt thử từ hàng lớn nhất tới hàng nhỏ nhất
với mỗi hàng i, lần lượt thử với các chữ số 1, 3, 5, 7, 9
* Các hàng chưa điền có tổng cộng 5^i cách điền
- nếu 5^i < n trừ ra khỏi n
- 5^i >= n thì chuyển sang hàng tiếp theo
*/

#define int long long
int quantity(int length){
    return pow(5, length); // {1, 3, 5, 7, 9}
}

void calculate(int n){
    int length;
    for (length = 1; ; length += 2){
        int tmp = quantity(length);
        if (tmp < n) n -= tmp;
        else break;
    }

    int number[length] = {};
    for (int pos = length-1; pos >= 0; pos--){
        for (int d = 1; d <= 9; d += 2){
            int tmp = quantity(pos);
            if (tmp < n)
                n -= tmp;
            else {
                number[pos] = d;
                break;
            }
        }
    }

    for (int i = length-1; i >= 0; i--) std::cout << number[i];
}

signed main()
{
    long long n;
    std::cin >> n;

    calculate(n);
}
