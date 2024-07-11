#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";
#define str string

str ghep(str a, str b, str c) {
    return a + b + c;
}
bool cmp(str x, str y) { // x < y?
    for (int i = 0; i < y.size(); i++) {
        if (x[i] < y[i]) return 1;
        if (x[i] > y[i]) return 0;
    }
    return 0;
}
bool mxm(str &x, str y) {
    return cmp(x, y) ? x = y, 1 : 0;
}

int main() {
    str a, b, c; cin >> a >> b >> c;
    str res = ghep(a, b, c);
    mxm(res, ghep(a, c, b));
    mxm(res, ghep(b, a, c));
    mxm(res, ghep(b, c, a));
    mxm(res, ghep(c, a, b));
    mxm(res, ghep(c, b, a));
    cout << res;
}
