#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";

const int N = 5e6 + 1;
int m, a, b, val[N];

int main() {
    cin >> m >> a >> b;

    iota(val, val + b - a + 1, a);

    for (int i = 2; i <= m; i++) {
        for (int j = (a - 1) / i * i + i; j <= b; j += i) {
            while (val[j - a] % i == 0) val[j - a] /= i;
        }
    }

    int cnt = 0;
    for (int i = 0; i <= b - a; i++) {
        cnt += val[i] == 1;
    }
    cout << cnt;
}
/*
duyệt ước 2->m, tìm bội của nó trong [a, b], chia hết. nếu số đó = 1 -> cnt++
*/