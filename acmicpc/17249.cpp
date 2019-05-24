#include <iostream>
using namespace std;

int main()
{
	bool flag = false;
	int left = 0, right = 0;
	string s;

	cin >> s;

	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '(')
			flag = true;
		if (!flag && s[i] == '@')
			left++;
		if (flag && s[i] == '@')
			right++;
	}

	cout << left << " " << right << '\n';

	return 0;
}
