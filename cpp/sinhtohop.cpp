#include <iostream>
#include <cmath>
using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define debug cout << "dfad\n";
#define int long long

int n, k, cnt;
bool mark[17];
int num[17];
void check() {
    long long res = 1;
    for (int i = 1; i <= k; i++) put(num[i]), res *= num[i];
    cout << '\n';
    cnt += (sqrt(res) == (int)(sqrt(res)));
}
void dq(int pos, int tight) {
    if (pos == k+1) {
        check();
        return;
    }
    for (int i = tight; i <= n; i++) {
        num[pos] = i;
        dq(pos + 1, i + 1);
        num[pos] = 0;
    }
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    see(n, k);

    dq(1, 1);

    cout << cnt;
}