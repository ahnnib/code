#include <iostream>
#include <deque>
using namespace std;

#define debug cout << "dfad\n";
#define ll long long

int n, m, q; deque<int> a, b;

void q1(int x) { // bo vao tui doraemon
    a.push_front(x);
    int tmp = a.back(); a.pop_back();
    b.push_back(tmp);
    int tmp2 = b.front(); b.pop_front();
    cout << tmp2;
}
void q2(int x) { // bo vao tui dorami
    b.push_front(x);
    int tmp = b.back(); b.pop_back();
    a.push_back(tmp);
    int tmp2 = a.front(); a.pop_front();
    cout << tmp2;
}
signed main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x; b.push_back(x);
    }

    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) q1(x);
        if (type == 2) q2(x);
        cout << '\n';
    }
}
/*
1 3 7 2
4 7 5 1 5

3 1 3 7
7 5 1 5 2 -> 4

4 3 1 3
5 1 5 2 7 -> 7

3 1 3 7 -> 4
2 5 1 5 2
*/
