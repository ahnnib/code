#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
	long long n; string s;
	cin >> n >> s;
	vector<long long> va;
	for (string sul : {"mapie", "pie", "map"}) {
        cout << sul << ' ';
		for (size_t pos = 0; (pos = s.find(sul, pos)) != string::npos;) {
			s[pos + sul.length() / 2] = '?';
			va.push_back(pos + sul.length() / 2);
		}
	}

// cout << s;
	cout << va.size();

    cout << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    long long NTT; cin >> NTT; while (NTT--) {
        solve();
    }
}