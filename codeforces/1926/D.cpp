#include <iostream>
#include <map>
using namespace std;

const int MAX = 2147483647;
/*
Nhận xét:
- Mỗi nhóm chỉ có nhiều nhất 2 số.
- 2 số x, y có thể cùng 1 nhóm khi và chỉ khi x ^ y = 2147483647
2147483647 ^ x = y
*/
void solve() {
    int ans = 0; map<int, int> cnt;
    int n; cin >> n; for (int i = 0; i < n; i++) {
        int a; cin >> a;
        // a[i] ^ a[j] = MAX (i < j)
        // a[i] = a[j] ^ MAX
        // a[j] = a[i] ^ MAX
        if (!cnt[a]) cnt[MAX ^ a]++, ++ans; // với số a[j], chưa gặp số a[i] (i < j) sao cho ghép cặp đc
        else cnt[a]--; // có cnt số a[i] trước đó ghép đc với a[j] = a[i] ^ MAX hiện tại
    }
    cout << ans << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; cin >> t; while (t--) {
        solve();
    }
}
