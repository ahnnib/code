#include <iostream>
#include <set>
using namespace std;

#define int long

signed main()
{
    int n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2) return cout << "NO", 0;
    else cout << "YES\n";

    int n1 = n - n % 2;
    set<int> s1, s2;
    for (int i = 1; i <= n1 / 2; i++)
    {
        if (i % 2) s1.insert(i), s1.insert(n1 - i + 1);
        else s2.insert(i), s2.insert(n1 - i + 1);
    }
    if (n != n1) s2.insert(n);

    cout << s1.size() << '\n';
    for (int i : s1) cout << i << ' ';
    cout << '\n';
    cout << s2.size() << '\n';
    for (int i : s2) cout << i << ' ';
}
