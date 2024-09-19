#include <iostream>
using namespace std;
#define int long long

const int N = 1e6 + 1;
bool com[N]; int uoc[N], qr[N];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    com[0] = com[1] = 1;
    for (int i = 2; i * i < N; i++) if (!com[i])
        for (int j = i * i; j < N; j += i) com[j] = 1;
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) uoc[j]++;
    for (int i = 1; i < N; i++)
        qr[i] = qr[i-1] + !com[uoc[i]];

    int t = 1;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << qr[b] - qr[a-1] << '\n';
    }
}
