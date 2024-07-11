#include <iostream>
#include <vector>
using namespace std;

struct T {int val, lvl; char t; }; // val, lvl, type
vector<T> v;
vector<char> func; vector<int> num;

int m, n, o[10][27]; string f;

bool is_func(int pos) { return f.substr(pos, 3) == "SUM" || f.substr(pos, 3) == "MAX"; }
bool is_num(int pos) { return '1' <= f[pos+1] && f[pos+1] <= '9'; }
int get_num(int pos) { return o[f[pos+1] - '1'][f[pos] - 'A']; }
/*
SUM(MAX(A1,B2),MAX(A2,B1))
MAX(SUM(C1,C2),SUM(B1,MAX(A3,A9)))


MAX
SUM
MAX

A3
B1
C1 + C2
*/

void solve() {
    cin >> f;

    v.clear();

    int i = 0;
    for (; i < f.size(); i++) {
        if (is_func(i)) func.push_back(f[i]);
        if (is_num(i)) num.push_back(get_num(i));
    }

    for (auto i : func) cout << i << ' '; cout << '\n';
    for (auto i : num) cout << i << ' ';

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    cin >> m >> n; for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> o[i][j];

    long long q; cin >> q; while (q--) {
        solve();
    }
}