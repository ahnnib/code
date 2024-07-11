#include <iostream>
#include <map>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int n;
    cin >> n;
    int a[n+1] = {};
    map<int, int> mm;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (mm[a[i]] == 0) mm[a[i]] = i;
    }

    // for (auto &[a, val] : mm) cout << a << ' ' << val << '\n';

    int solan𝕏xuathientrongdaya = 0;
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int 𝕏;
        cin >> 𝕏;
        if (mm[𝕏] == 0) cout << "-1\n";
        else cout << mm[𝕏] << '\n', solan𝕏xuathientrongdaya++;
    }

    //1: so lan 𝕏 xuat hien nhieu hown so lan 𝕏 khong xuat hien
    // cout << solan𝕏xuathientrongdaya << '\n';
    if (solan𝕏xuathientrongdaya > t - solan𝕏xuathientrongdaya) cout << 1;
    else if (solan𝕏xuathientrongdaya < t - solan𝕏xuathientrongdaya) cout << -1;
    else cout << 0;
}