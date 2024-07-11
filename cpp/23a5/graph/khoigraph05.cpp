#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char A[4][4], B[4][4];
        for (int i = 1; i < 4; i++) for (int j = 1; j < 4; j++) cin >> A[i][j];
        for (int i = 1; i < 4; i++) for (int j = 1; j < 4; j++) cin >> B[i][j];

        if (A[2][2] != B[2][2]) { cout << "NO\n"; continue; }
        string SA, SB; // tạo chu trình (xâu)
        SA = SA + A[1][1] + A[2][3] + A[3][1] + A[1][2] + A[3][3] + A[2][1] + A[1][3] + A[3][2];
        SB = SB + B[1][1] + B[2][3] + B[3][1] + B[1][2] + B[3][3] + B[2][1] + B[1][3] + B[3][2];
        // xóa kí tự .
        for (int i = 0; i < SA.size(); i++) if (SA[i] == '.') SA.erase(i, 1), i--;
        for (int i = 0; i < SB.size(); i++) if (SB[i] == '.') SB.erase(i, 1), i--;
        // cout << SA << ' ' << SB << '\n';

        if (SA == SB) {cout << "YES\n"; continue; }
        if (SA.size() == SB.size() && SA.size() == 8) { cout << "NO\n"; continue; }
        bool c = 1;
        for (int _ = 0; _ < 4; _++)
        {
            SA = SA + SA[0];
            SA.erase(0, 1);
            if (SA == SB) { c = 0; break; }
        }
        if (c == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}