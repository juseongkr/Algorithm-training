#include <iostream>
using namespace std;

int x, y;
string s;

int main()
{
	cin >> s;
	if (s[0] == '1')
		x++;
	else
		y++;

	for (int i=1; i<s.length(); ++i) {
		if (s[i-1] != s[i]) {
			if (s[i] == '1')
				x++;
			else
				y++;
		}
	}

	cout << min(x, y) << '\n';

	return 0;
}
