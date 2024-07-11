#include <iostream>
using namespace std;

#define debug cout << "dafd\n";

int m, n, o[9][27]; string f;

bool is_char(int pos) { return 'A' <= f[pos] && f[pos] <= 'Z'; }
bool is_num(int pos) { return '1' <= f[pos] && f[pos] <= '9'; }

bool is_address(int pos) { return is_char(pos) && is_num(pos + 1); }
bool is_func(int pos) { return is_char(pos) && is_char(pos + 1); }

int func_length(int pos) { int i = pos + 4; while (f[i] != ')') i++; return i - pos + 1; }

int num(string address) { return o[address[1] - '1'][address[0] - 'A']; } // địa chỉ -> số
string get_address(int pos) { return f.substr(pos, 2); } // trả về xâu địa chỉ ô
string get_num(int pos) { return to_string(num(get_address(pos))); } // trả về xâu val
string MAX(string n1, string n2) { return stoi(n1) > stoi(n2) ? n1 : n2; } // so sánh 2 xâu val
void replace_num(int pos) { f.replace(pos, func_length(pos), get_num(pos)); } // thay địa chỉ bởi xâu số
void replace_func(int pos, int num) {f.replace()}
void process(int pos, char type) {
    // cout << "current obj: " << pos << ' ' << type << '\n';
    cout << f << '\n';
    if (pos >= f.size()) return;
    // nếu pos là hàm: tiếp tục đệ quy, cuối cùng replace pos là số kq của hàm
    // nếu pos là số: ko làm gì cả
    if (is_num(pos)) return;
    if (is_address(pos)) { replace_num(pos); return; }
    // nếu pos là hàm
    // cout << "getting function " << f[pos] << " at " << pos << '\n';
    process(pos + 4, f[pos]);
    process(pos + 7, f[pos]);

    string num1 = get_num(pos + 4),
        num2 = get_num(pos + 7);

    // nếu pos là hàm
    // nếu số thứ 2 là hàm

    // cout << num1 << ' ' << num2 << ' ';
    // return (f[pos] == 'S' ? num1 + num2 : max(num1, num2));
    // if (f[pos] == 'M') { cout << "got max " << max(num1, num2) << '\n'; return max(num1, num2); }
    // if (f[pos] == 'S') { cout << "got sum " << num1 + num2 << '\n'; return num1 + num2; }
    if (type == 'M') replace_func(pos, 2, MAX(num1, num2));
    if (type == 'S') replace_num(pos, 2, num1 + num2);
}

void sub1() {
    int num1 = o[f[5] - '1'][f[4] - 'A'],
        num2 = o[f[8] - '1'][f[7] - 'A'];
    cout << (f[0] == 'S' ? num1 + num2 : max(num1, num2));
}
void sub2() {
    process(0, f[0]);
    // cout << get_num(0);
    cout << f;
}
void solve() {
    cin >> f;

    sub2();
    // if (f.size() == 10) sub1();
    // else sub2();

    cout << '\n';
}

int main()
{
    // std::ios_base::sync_with_stdio(0);
    // std::cin.tie(0); std::cout.tie(0);

    cin >> m >> n; for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> o[i][j];

    int q; cin >> q; while (q--) {
        solve();
    }
}
/*
2 2
1 2
3 4
1
SUM(MAX(A1,B2),A2)

4 + 3 = 7
*/