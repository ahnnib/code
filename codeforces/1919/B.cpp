#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n; string s;
        cin >> n >> s;

        int res = 0;
        for (char i : s)
        {
            if (i == '+') res++;
            if (i == '-') res--;
        }

        cout << abs(res) << '\n';
    }
}
/*
Tóm tắt:
1000 test
n = |s|
xâu s (s[i] = {+; -}) -> dãy a, a[i] = {1; -1}

Định nghĩa hàm p: cho bộ c m số. Khi đó p(c) = \sum{c} * m

Yêu câu: Tách a thành k dãy b != {}, là dãy con liên tiếp của a sao cho \sum{p_bi} min

+---++++-+++++---++-
số +: 12
số -: 8
đáp án: abs(số + trừ số -)
*/