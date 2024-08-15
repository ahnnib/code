#include <iostream>
using namespace std;
#define ll long long
#define debug cout << "dfad\n";
const int N = 1e7+1;
bool com[N];
int main() {
    int n; cin >> n;
    com[0] = com[1] = 1;
    for (int i = 1; i*i < N; i++) if (com[i] == 0)
        for (int j = i*i; j < N; j += i) com[j] = 1;
    for (int i = 2; i <= n; i++) {
        if (!com[i]) {
            int rev = 0, ii = i; while (ii) rev = rev * 10 + (ii%10), ii /= 10;
            if (!com[rev]) cout << i << ' ';
        }
    }
}