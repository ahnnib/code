#include <iostream>
using namespace std;
#define int long long
void winhmm() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if(a > c && b > d) res ++;
    if(a > c && b == d) res ++;
    if(a == c && b > d) res ++;
    if(a > d && b > c) res ++;
    if(a > d && b == c) res ++;
    if(a == d && b > c) res ++;
    cout << res * 2 << '\n';
}
main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++)
        winhmm();
}
