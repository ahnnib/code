#include <iostream>
#include <algorithm>
#include <math.h>

#define int long long
#define debug std::cout << "dfad\n";

int i = 0;

std::string s;
char op = '+';

struct frac
{
    int n;
    int d;
};

bool isnum(char ch) { return ('0' <= ch && ch <= '9'); }
bool isop(char ch) { return(ch == '+' || ch == '-' || ch == '*' || ch == ':'); }

frac getfrac(std::string s)
{
    frac res = {0, 0};

    for (; i < s.size() && isnum(s[i]); i++)
        res.n = res.n * 10 + s[i]-48;
    i++;
    for (; i < s.size() && isnum(s[i]); i++)
        res.d = res.d * 10 + s[i]-48;

    // std::cout << res.n << ' ' << res.d << '\n';
    return res;
}

frac add_subt(frac a, frac b)
{
    frac res;

    int lcm = a.d / std::__gcd(a.d, b.d) * b.d;
    int ga = lcm / a.d;
    int gb = lcm / b.d;

    if (op == '+') res.n = a.n*ga + b.n*gb;
    if (op == '-') res.n = a.n*ga - b.n*gb;
    res.d = lcm;

    int gcd = std::__gcd(res.n, res.d);
    // std::cout << lcm << ' ' << ga << ' ' << gb;
    // std::cout << ' ' << res.n << ' ' << res.d << ' ' << gcd << '\n';
    return {res.n/gcd, res.d/gcd};
} // 1/3 + 2/9 - 1/5 = 16/45

frac mul_div(frac a, frac b)
{
    frac res;
    if (op == ':') std::swap(b.n, b.d);
    res.n = a.n * b.n;
    res.d = a.d * b.d;
    int gcd = std::__gcd(res.n, res.d);
    return {res.n/gcd, res.d/gcd};
}

signed main()
{
    std::cin >> s;
    frac ans = {0, 0};
    ans = getfrac(s);

    frac tmp = {0, 0};

    while (i < s.size())
    {
        if (isnum(s[i]))
        {
            if (op == '+' || op == '-')
                ans = add_subt(ans, getfrac(s));
            if (op == '*' || op == ':')
                ans = mul_div(ans, getfrac(s));
        }
        if (isop(s[i])) op = s[i], i++;
    // std::cout << ans.n << '/' << ans.d << '\n';
    // std::cout << i << '\n';
    }

    std::cout << ans.n << '/' << ans.d << '\n';
}