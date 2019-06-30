#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<char, int> dict = { {'(', 1}, {')', -1}, {'{', 2}, {'}', -2}, {'[', 3}, {']', -3}};
	int ans = 0, val = 0;
	string s;

	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if (dict.count(s[i]))
			val += dict[s[i]];
		else
			ans = max(ans, val);
	}
	cout << ans << '\n';

	return 0;
}
