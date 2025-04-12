#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define ll long long
#define dbg cout << "dfad\n";

map<string, bool> p;
map<string, int> score;
map<string, int> result;
vector<string> ans;

int main() {
    freopen("contest.inp", "r", stdin);
    freopen("contest.out", "w", stdout);
    int n, z, s; cin >> n >> z >> s;

    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        ans.push_back(name);
    }

    for (int i = 0; i < z; i++) {
        string s; int t;
        cin >> s >> t;
        score[s] = t;
    }

    for (int i = 0; i < s; i++) {
        string name, prob, status;
        cin >> name >> prob >> status;
        if (status == "AC") {
            result[name] += score[prob];
        }
    }

    for (string i : ans) {
        cout << i << ' ' << result[i] << '\n';
    }
}