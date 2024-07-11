#include <iostream>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	#ifndef ONLINE_JUDGE
	#else
	freopen("trapbracket.inp", "r", stdin);
	freopen("trapbracket.out", "w", stdout);
	#endif

	int n;
	std::cin >> n;
	std::string s;
	std::cin.ignore();

	while (n--)
	{
		std::getline(std::cin, s);

		// std::cout << "dfdfdfdfdfdfddfd: " << s << '\n';
		bool c = 1;

		std::stack<char> stack;
		for (char i : s)
		{
			if (i != '(' && i != ')') { c = 0; break; }

			if (i == '(') stack.push(i);
			if (i == ')') {
				if (!stack.empty() && stack.top() == '(') stack.pop();
				else c = 0;
			}
		}

		if (!stack.empty()) c = 0;

		std::cout << c << '\n';
	}
}
/*
()(())
*/