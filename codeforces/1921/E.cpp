#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

int main()
{
    int query; cin >> query; while (query--) {
        int h, w, xa, ya, xb, yb;
        cin >> h >> w >> xa >> ya >> xb >> yb;

        string winner; bool win;

        if ((xa - xb) % 2 == 0) {
            winner = "Bob";
            int diag;
            if (xa - xb >= 0) win = false;
            else if (ya == yb) win = true;
            else {
                if (ya < yb) diag = yb - 1;
                else diag = w - yb;
                win = xb - 2 * diag >= xa;
            }
        }
        else {
            winner = "Alice";
            int diag;

            xa++;
            if (ya > yb) ya--; if (ya < yb) ya++;

            if (xa - xb > 0) win = false;
            else if (ya == yb) win = true;
            else {
                if (ya < yb) diag = w - ya;
                else diag = ya - 1;
                win = xb - 2 * diag >= xa;
            }
        }

        cout << (win ? winner : "draw") << '\n';
    }
}
/*
12
6 5 2 2 5 3
4 1 2 1 4 1
1 4 1 3 1 1
5 5 1 4 5 2
4 4 1 1 4 4
10 10 1 6 10 8
10 10 2 6 10 7
10 10 9 1 8 1
10 10 8 1 10 2
10 10 1 1 2 1
10 10 1 3 4 1
10 10 3 1 1 1

*/