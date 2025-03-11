/*#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Hàm kiểm tra liệu có thể đạt độ an toàn tối thiểu L với n kho
bool canAssign(int n, const vector<int>& P, int L) {
    int total_kho = 0;
    for (int p : P) {
        total_kho += p / L; // Số kho mà nhân viên này có thể quản lý
        if (total_kho >= n) return true; // Nếu đã đủ số kho
    }
    return false;
}

// Hàm tính tổng chi phí khi đạt độ an toàn tối thiểu L
int calculateCost(int n, const vector<int>& P, int L) {
    int cost = 0;
    int total_kho = 0;
    for (int p : P) {
        int k = p / L; // Số kho mà nhân viên này quản lý
        if (k > 0) {
            cost += p; // Tính lương nhân viên này
            total_kho += k;
        }
        if (total_kho >= n) break; // Nếu đã đủ số kho
    }
    return cost;
}

int main() {
    freopen("QLK.INP", "r", stdin);
    freopen("QLK.OUT", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> P(m);
    for (int i = 0; i < m; ++i) {
        cin >> P[i];
    }

    // Tìm kiếm nhị phân trên giá trị L
    int left = 1, right = *max_element(P.begin(), P.end());
    int best_L = 0, best_Y = INT_MAX;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canAssign(n, P, mid)) { // Kiểm tra khả năng phân công với L = mid
            int cost = calculateCost(n, P, mid);
            if (mid > best_L || (mid == best_L && cost < best_Y)) {
                best_L = mid;
                best_Y = cost;
            }
            left = mid + 1; // Tăng giá trị L để tìm giá trị lớn hơn
        } else {
            right = mid - 1; // Giảm giá trị L để tìm giá trị nhỏ hơn
        }
    }

    if (best_L == 0) best_Y = 0;

    cout << best_L << " " << best_Y << endl;
}
*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

using i16 = short int;
using i32 = int32_t;
using i64 = int64_t;
using ui16 = unsigned short int;
using ui32 = uint32_t;
using ui64 = uint64_t;

template<class T>
using v = vector<T>;

#define all(a) (a).begin(), (a).end()
#define open(x) freopen(#x ".inp", "r", stdin), freopen(#x ".out", "w", stdout)

template<class X, class Y> bool mimi(X &x, const Y &y) {if(x > y) {x = y; return 1;} return 0;}
template<class X, class Y> bool mama(X &x, const Y &y) {if(x < y) {x = y; return 1;} return 0;}

const i32 N = 2 * 1e5;
const i32 M = 1000000007;
const i32 inf = 1000000009;
const i64 infll = (i64)1000000000000000018;

void sad(i32 testID) {
    i32 n, m; cin >> m >> n;
    i32 a[n];
    for(i32 i = 0; i < n; i ++) cin >> a[i];
    i32 l = 1, r = 1e9, res = 0;
    function<bool(i32)> check = [&](i32 x) {
        i32 sum = 0;
        for(i32 i = 0; i < n; i ++) sum += a[i] / x;
        return sum >= m;
    };
    while(l <= r) {
        i32 mid = (r + l) >> 1;
        if(check(mid)) l = (res = mid) + 1;
        else r = mid - 1;
    }
    cout << res << ' ';
    if(res == 0) {cout << 0 << endl; return;}
    i32 dp[5 * m + 1]; memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(i32 i = 0; i < n; i ++) {
        for(i32 j = m * 5 - a[i] / res; j >= 0; j --) mimi(dp[j + a[i] / res], dp[j] + a[i]);
    }
    cout << *min_element(dp + m, dp + m * 5 + 1) << endl;
}

i32 main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    open(QLK);

    i32 t = 1;
    // cin >> t;
    for(i32 testID = 1; testID <= t; testID++) {
        // cout << "Case #" << testID << ":\n";
        sad(testID);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << endl << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    return 0;
}