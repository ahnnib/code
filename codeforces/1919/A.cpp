#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        bool player = 0; // 0: Alice 1: Bob

        if (a < b && !player) swap(a, b);
        else if (a > b && player) swap(a, b);

        if (abs(a - b) % 2) player = !player;

        // a = b
        player = !player;

        cout << (player ? "Bob\n" : "Alice\n");
    }
}
/*
số lần swap qua lại = chênh lệch a, b
nhận thấy người chơi sẽ cố gắng đổi lấy ví nhiều nhất
lấy ví dụ a = 3, b = 1, p = 1
a = 1, b = 3, p = 1
a = 1, b = 2, p = 1
a = 1, b = 2, p = 0
a = 2, b = 1, p = 0
a = 1, b = 1, p = 0
suy ra lúc a = b, người chơi tiếp theo?
khi đó trừ ra (xét if( a == b))...
rồi lặp lại
vd2
a = 3, b = 3, p = 0
a = 2, b = 3, p = 0
a = 2, b = 3, p = 1
a = 2, b = 2, p = 1
a = 2, b = 2, p = 0
a = 1, b = 2, p = 0
a = 1, b = 2, p = 1
a = 1, b = 1, p = 1
a = 1, b = 1, p = 0
a = 0, b = 1, p = 0
a = 0, b = 1, p = 1
a = 0, b = 0, p = 0

vậy khi a == b thì người thắng sẽ là người kia
*/

