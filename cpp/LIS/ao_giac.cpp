#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "dplis1";
// Số test kiểm tra
const int NTEST = 2;

#define debug cout << "dafd\n";

mt19937 rd(chrono::high_resolution_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    // assert(l <= h);
    // return l + rd() * 1LL * rd() % (h - l + 1);
    return uniform_int_distribution<long long>(l, h)(rd);
}

int main()
{
    srand(time(NULL));

    system(("g++ " + NAME + ".cpp -o " + NAME).c_str());
    system(("g++ " + NAME + "_AC.cpp -o " + NAME).c_str());

    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        long long n = Rand(1, 10);
        inp << n << '\n';
        for (int i = 0; i < n; i++) inp << Rand(1, 15) << ' ';
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system((NAME + ".exe").c_str());
        system((NAME + "_AC.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}