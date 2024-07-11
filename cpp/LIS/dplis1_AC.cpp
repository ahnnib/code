#include <bits/stdc++.h>                                                                                                                                                                                      //Logm
using namespace std;
#define int long long

const int N = 1e5+5;
int n, a[N];

vector<int> val;
int comp[N];

int bit[N];
void update(int i, int val) { // dp[i] = val
    for (; i < N; i += i & -i)
        bit[i] = max(bit[i], val);
}
int getmax(int i) { // lấy max(dp[1..i])
    int res = 0;
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

signed main() {
    ifstream cin("dplis1.inp");
    ofstream cout("dplis1.ans");

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    // sắp xếp tất cả giá trị và loại bỏ đi những giá trị trùng lặp
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    // {2, 10, 4, 5, 2, 4, 4} -> {2, 4, 5, 10}

    // lưu ý vì ctdl bit không thể update hay get ở vị trí 0
    // nên cần +2 giá trị nén để không bị tràn
    for (int i = 1; i <= n; ++i)
        comp[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 2;
    // a = {2, 10, 4, 5, 2, 4, 4}
    // comp = {2, 5, 3, 4, 2, 3, 3}

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int last = getmax(comp[i] - 1); // tìm dp[x] lớn nhất với x < a[i]
        // vì ở đây lấy max có vị trí comp[i] - 1 nên comp[i] phải > 1
        update(comp[i], last + a[i]); // thêm a[i] vào dp[x] lớn nhất và cập nhật cho dp[a[i]]
        ans = max(ans, last + a[i]); // lấy max kết quả
    }
    cout << ans;
    return 0;
}
