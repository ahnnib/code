#include <iostream>
using namespace std;

struct Vector
{
    long long x, y;
};

// double Len(const TVector &u)
// {
//     return sqrt(u.x * u.x + u.y * u.y);
// }

// TCoord SqrLen(const TVector &u)
// {
//     return u.x * u.x + u.y * u.y;
// }

long long CrossProduct(Vector &v1, Vector &v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

int main()
{
    int t;
    cin >> t;
    while (t --> 0)
    {
        Vector p1, p2, p3;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

        Vector p1p2;
        p1p2.x = p2.x - p1.x;
        p1p2.y = p2.y - p1.y;
        Vector p1p3;
        p1p3.x = p3.x - p1.x;
        p1p3.y = p3.y - p1.y;

        long long ans = CrossProduct(p1p2, p1p3);
        cout << ans << ' ';

        if (ans < 0) cout << "RIGHT\n";
        if (ans > 0) cout << "LEFT\n";
        if (ans == 0) cout << "TOUCH\n";
    }
}