#include <iostream>
using namespace std;

#define debug cout << "dfad\n";

int h, w, xa, ya, xb, yb;
string winner;

int main()
{
    // int q; cin >> q; while (q--) {
        cin >> h >> w >> xa >> ya >> xb >> yb;

        winner = "";

        int t = (xa - xb);

        if (t >= 0) { cout << "draw\n"; }
        else{
        if (t % 2 == 0) {
            winner = "Bob";
            if (t >= 0) winner = "draw";
            int diag;
            if (ya > yb) diag = w - yb;
            if (ya < yb) diag = yb - 1;
            if (!(xb - xa >= 2 * diag)) winner = "draw";
        }
        else {
            winner = "Alice";

            xa++;
            if (ya > yb) ya--; if (ya < yb) ya++;

            int diag;
            if (ya > yb) diag = w - yb;
            if (ya < yb) diag = yb - 1;
            if (!(xb - xa >= 2 * diag)) winner = "draw";
        }

        cout << winner << '\n';
        }
    // }
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