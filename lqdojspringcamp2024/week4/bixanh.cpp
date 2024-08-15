#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

#define i128 __int128_t

void cin_128(i128 &x) {
    x = 0;
    string t; cin >> t; for (int i = 0; i < t.size(); i++) {
        x = x * 10 + (t[i] - 48);
    }
}
void cout_128(i128 x) {
    string t; while (x) t += char(x % 10 + 48), x /= 10;
    for (int i = t.size()-1; i >= 0; i--) cout << t[i];
}
// 8 4 11
int main() {
    i128 a, b, x;
    cin_128(a);
    cin_128(b);
    cin_128(x);
    i128 cnt = 0;
    i128 rem = x % a;
    if (rem != 0) {
        i128 t = a - rem + b - 1;
        if (t % b == 0) {
            cout << -1;
            return 0;
        }
        cnt += t / b;
        x += cnt * b;
    }
    cnt += x / a;
    cout_128(cnt);
}