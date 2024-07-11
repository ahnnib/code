#include <iostream>
#include <vector>
using namespace std;

struct Vector {long long x, y;};

long long cross(Vector &p1, Vector &p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int main()
{
    int n;
    cin >> n;

    vector< Vector > p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    p.push_back(p[0]);

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        Vector v1 = {p[i].x, p[i].y};
        Vector v2 = {p[i+1].x, p[i+1].y};
        // cout << cross(v1, v2) << ' ';
        ans += cross(v1, v2);
    }

    cout << abs(ans) << '\n';
}