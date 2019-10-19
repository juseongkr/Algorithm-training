#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool solve(string s)
{
	string p = s;
	bool flag = false;
	do {
		if (flag) {
			cout << s << '\n';
			return true;
		}
		if (p == s)
			flag = true;
	} while(next_permutation(s.begin(), s.end()));
	return false;
}

int main()
{
	string s;
	int t;

	cin >> t;
	while (t--) {
		cin >> s;
		if (!solve(s))
			cout << s << '\n';
	}

	return 0;
}
