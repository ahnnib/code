// https://lqdoj.edu.vn/problem/incsubseq
#include <iostream>
using namespace std;

#define ll long long
#define debug cout << "dfad\n";

int main() {
    int n; cin >> n;
    // duy tri mang 1 co ptu cuoi luon < mang 2
    // neu a[i] cung lon/be hon -> bo vao mang 1
    // ko thi bo vao mang 2
    int v1 = 1e9, v2 = 1e9;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > v1 && a > v2) v1 = a, cnt++;
        else if (a <= v1 && a <= v2) v1 = a;
        else v2 = a;
        if (v1 > v2) swap(v1, v2);
    }
    cout << cnt;
}