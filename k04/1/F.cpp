#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int> > pq;
    int x, n; cin >> x >> n;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        pq.push(d);
    }

    long long res = 0;
    while (pq.size() > 1) {
        int d1 = pq.top(); pq.pop();
        int d2 = pq.top(); pq.pop();
        res += d1 + d2;
        pq.push(d1 + d2);
    }
    cout << res;
}