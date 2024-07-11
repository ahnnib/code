#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

bool cmp( pair<int, int> &a, pair<int, int> &b) {
    return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
}

signed main()
{
    // for (int i = 1; i <= 50; i++) { for (int j = 1; j <= 50; j++) { cout << i*i + j*j << ' '; } cout << '\n'; }

    int k; cin >> k;

    vector< pair<int, int> > v;
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            v.push_back({i, j});
        }
    }
    sort(begin(v), end(v), cmp);

    for (auto i : v)
    {
        k -= 2;
        if (i.first == i.second) k += 1;
        if (k <= 0) {
            cout << i.first * i.first + i.second * i.second;
            return 0;
        }
    }
}
/*
hàng lẻ: có ô chéo
hàng chẵn: không có ô chéo
1 3 5 7
0 2 4 6
đường chéo nối (u, 0) (0, u): u ô

bảng đổi xứng nhau qua đường chéo (1, 1) (n, n)
nên ta chỉ xét 1 nửa
với mỗi nửa duyệt lần lần insert cặp (i, j) đồng
thời trừ biến k đi
đến khi = 0
in ra cặp cuối cùng (lớn nhất)
*/