#include <iostream>
#include <algorithm>
using namespace std;

#define Int __int128_t
istream &operator >> (istream &st, Int &a) {string s;a=0;st>>s;bool g=1;for(int i=0;i<s.size();i++){if(i==0&&s[i]=='-'){g = 0;continue;}a=a*10+s[i]-'0';}if(!g)a=-a;return st;}
ostream &operator << (ostream &st, const Int &a) {Int t=a;if(t==0){st<<0;return st;}if(t<0){st<<'-';t=-t;}string b;while(t!=0){b.push_back((t%10+'0'));t/=10;}reverse(b.begin(),b.end());st<<b;return st;}
template<typename... T> void see(T&... args) { ((cin >> args), ...); }
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n'; }
#define seea(a, x, n) for (int i = x; i <= n; i++) cin >> a[i];
#define puta(a, x, n) for (int i = x; i <= n; i++) cout << a[i] << " \n"[i == n];
#define debug cout << "dfad\n";
#define ll long long

Int n, m;

struct mat {
    Int m[3][3] = {};
} base;
mat operator * (const mat &a, const mat &b) {
    mat res;
    for (int i : {0,1,2}) for (int j : {0,1,2}) {
        for (int k : {0,1,2}) {
            res.m[i][j] += a.m[i][k] * b.m[k][j];
            res.m[i][j] %= m;
        }
    }
    return res;
}
mat powm(mat a, Int n) {
    if (n < 0) return base;
    if (n == 0) return base;
    if (n == 1) return a;
    mat T = powm(a, n>>1);
    T = T * T;
    if (n & 1) return T * a;
    else return T;
}
void printm(mat &m) {
    for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) cout << m.m[i][j] << " \n"[j == 2];
}
signed main()
{
    base.m[0][0] = base.m[1][1] = base.m[2][2] = 1;
    cin >> n >> m;

    mat a; a.m[0][0] = 1; a.m[0][1] = 2; a.m[0][2] = 4;
    mat b;

    b.m[0][0] = b.m[1][0] = b.m[2][0] = 1;
    b.m[0][1] = 1; b.m[1][1] = 2; b.m[2][1] = 2;
    b.m[0][2] = 2; b.m[1][2] = 3; b.m[2][2] = 4;

    // printm(a);
    // putl(n / 3);
    mat c = powm(b, (n - 1) / 3);
    // printm(c);
    mat d = a * c;
    // printm(d);
    put(d.m[0][(n - 1) % 3]);
}
// 1 2 4 7 13 24 44 81 49 74