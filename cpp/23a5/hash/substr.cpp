#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    // cout << A << ' ' << B << "\n\n";
    int a = A.size(), b = B.size();

    string curr = A.substr(0, b);

    for (int i = 0; i + b - 1 < a; i++)
    {
        if (curr == B) cout << i+1 << ' ';
        cout << curr << '\n';
        curr.erase(0, 1); curr += A[i+b];
    }
}
/*
aaaaa
aa
*/