#include <iostream>
#include <iomanip>
using namespace std;

struct Point{
    long long x, y;
    Point(){}
    Point(long long x, long long y){
        this -> x = x;
        this -> y = y;
    }
};

#define Vector Point
Vector getVec(Point X, Point Y) { return {Y.x - X.x, Y.y - X.y}; }

Point operator + (Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
Point operator - (Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
Point operator * (Point a, int b) { return {a.x * b, a.y * b}; }
long long dot (Point a, Point b) { return a.x * b.x + a.y * b.y; }
long long cross (Point a, Point b) {  return a.x * b.y - a.y * b.x; }
long long sqLen (Point v) { return v.x * v.x + v.y * v.y; }  // nếu T là long double thì gộp với hàm dưới
#include <math.h>
long double length (Point v) { return sqrt(sqLen(v)); }

bool onSegment(Point X, Point Y, Point Z) // Z nam tren XY
{
    return min(X.x, Y.x) <= Z.x && Z.x <= max(X.x, Y.x) && \
           min(X.y, Y.y) <= Z.y && Z.y <= max(X.y, Y.y);
}

short ori(Point A, Point B, Point C)
{
    long long t = cross(getVec(A, B), getVec(A, C));
    if (t < 0) return -1;
    if (t > 0) return 1;
    if (t == 0) return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t --> 0)
    {
        Point A, B, C, D;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

        if (ori(A, B, C) != ori(A, B, D) && ori(C, D, A) != ori(C, D, B)) { cout << "YES\n"; continue; }
        if ((ori(A, B, C) == 0 && onSegment(A, B, C)) || (ori(A, B, D) == 0 && onSegment(A, B, D))) { cout << "YES\n"; continue; }
        if ((ori(C, D, A) == 0 && onSegment(C, D, A)) || (ori(C, D, B) == 0 && onSegment(C, D, B))) { cout << "YES\n"; continue; }
        cout << "NO\n";
    }
}
