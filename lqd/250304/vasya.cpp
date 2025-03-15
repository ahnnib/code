#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

// Hàm kiểm tra nếu có thể đạt được (x, y) với một đoạn thay đổi độ dài `len`
bool canReach(int x, int y, const vector<int>& prefixX, const vector<int>& prefixY, int n, int len) {
    for (int i = 0; i + len <= n; ++i) {
        // Tính tọa độ sau khi bỏ đoạn [i, i + len - 1]
        int dx = prefixX[n] - (prefixX[i + len] - prefixX[i]);
        int dy = prefixY[n] - (prefixY[i + len] - prefixY[i]);
        // Kiểm tra nếu có thể đạt được (x, y)
        if (abs(x - dx) + abs(y - dy) <= len && (len - abs(x - dx) - abs(y - dy)) % 2 == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("vasya.inp", "r", stdin);
    freopen("vasya.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    // Tính tổng dịch chuyển cần thiết
    int totalX = 0, totalY = 0;
    for (char c : s) {
        if (c == 'U') totalY++;
        else if (c == 'D') totalY--;
        else if (c == 'L') totalX--;
        else if (c == 'R') totalX++;
    }

    // Nếu không thể đạt được (x, y), in ra -1
    if ((abs(x - totalX) + abs(y - totalY)) > n || ((abs(x - totalX) + abs(y - totalY)) % 2 != 0)) {
        cout << -1 << endl;
        return 0;
    }

    // Tiền tố tọa độ
    vector<int> prefixX(n + 1, 0), prefixY(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixX[i + 1] = prefixX[i];
        prefixY[i + 1] = prefixY[i];
        if (s[i] == 'U') prefixY[i + 1]++;
        else if (s[i] == 'D') prefixY[i + 1]--;
        else if (s[i] == 'L') prefixX[i + 1]--;
        else if (s[i] == 'R') prefixX[i + 1]++;
    }

    // Tìm độ dài tối thiểu bằng tìm kiếm nhị phân
    int left = 0, right = n, result = INT_MAX;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canReach(x, y, prefixX, prefixY, n, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;
    return 0;
}
