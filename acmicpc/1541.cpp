#include <iostream>
using namespace std;

int main()
{
	string s, num;
	int ans = 0;
	char op = '+';

	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if (s[i] == '+' || s[i] == '-') {
			if (op == '+')
				ans += stoi(num);
			else
				ans -= stoi(num);
			
			if (s[i] == '-')
				op = '-';
			num = "";
		} else {
			num += s[i];
		}
	}
	if (op == '+')
		ans += stoi(num);
	else
		ans -= stoi(num);

	cout << ans << '\n';

	return 0;
}
