#include <iostream>

#define debug std::cout << "dfad\n";
#define debugg std::cout << "dfad dfad ";

#define int long long

struct Cell {
    char x;
    int y;
};

const int MOD = 1e9;
int mod(int a) {
    return (a >= 1e8 ? a % MOD : a);
}

signed main()
{
    freopen("excel.inp", "r", stdin);
    freopen("excel.out", "w", stdout);

    int cells[26][101] = {};

    int q;
    std::cin >> q;
    while (q--) {
        // char cx; int cy; std::string t;
        // std::cin >> cx >> cy >> t;

        Cell C; std::string t;
        std::cin >> C.x >> C.y >> t;

        C.x -= 65;

        // debugg std::cout << 'a' << t << 'b' << '\n';
        // debugg std::cout << (t == "SUM");
        if (t == "=") {
            int X;
            std::cin >> X;
            cells[C.y][C.x] = X;
        }

        else {
            int n;
            std::cin >> n;

            // int sum = 0;
            for (int i = 0; i < n; i++) {
                Cell tmp;
                std::cin >> tmp.x >> tmp.y;
                cells[C.y][C.x] = cells[C.y][C.x] +
                                  cells[tmp.y][tmp.x-65];
            }

            // debugg std::cout << cells[C.x][C.y] << '\n';
            if (t == "AVG") cells[C.y][C.x] /= n;
        }
    }
    // std::cout << '\n';

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 26; j++)
            std::cout << mod(cells[i][j]) << ' ';
        std::cout << '\n';
    }
}
/*
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
12 12 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 12 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/