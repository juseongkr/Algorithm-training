#include <iostream>
using namespace std;

int main()
{
	string s;

	cin >> s;
	for (int i=0; i<s.length(); ++i) {
		if (s[i]-3 < 'A')
			cout << char(s[i]+23);
		else
			cout << char(s[i]-3);
	}

	return 0;
}
